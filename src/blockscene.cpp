/*!
 * \file blockscene.cpp
 * \brief Source file for BlockScene class
 * \author Jiri Vozar
 * \author Vaclav Dolezal
 */

#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>

#include "blockscene.h"

BlockScene::BlockScene(QGraphicsView *parent)
    : QGraphicsScene(parent)
{
    viewParent = parent;
    line = nullptr;
    blocks.append(new BlockItem_vec3(this, 10, 20));
    blocks.append(new BlockItem_abs3(this, 210, 150));
    blocks.append(new BlockItem_num3(this, -100, 20));
    BlockPipe *p = new BlockPipe(this, blocks[0]->out_slots[0], blocks[1]->in_slots[0]);
    addItem(p);

    blocks[1]->compute();
}

BlockScene::~BlockScene()
{
    clearScene();
}

void BlockScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button() != Qt::LeftButton)
        return;

    // Start drawing of pipe
    QGraphicsItem *overItem = itemAt(mouseEvent->scenePos(), viewParent->transform());
    if (overItem) {
        BlockSlotOut *bs = dynamic_cast<BlockSlotOut *>(overItem);
        if (bs && !bs->getPipe()) {
        startingSlot = bs;
        line = new QGraphicsLineItem(QLineF(mouseEvent->scenePos(),
            mouseEvent->scenePos()));
        addItem(line);
        }
    }

    QGraphicsScene::mousePressEvent(mouseEvent);
}

void BlockScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    // Show values of slot or pipe when hovering over
    QGraphicsItem *overItem = itemAt(mouseEvent->scenePos(), viewParent->transform());
    if (overItem) {
        if (BlockSlot *bs = dynamic_cast<BlockSlot *>(overItem))
            updateLabel(bs->getValueString());
        else if (BlockPipe *bp = dynamic_cast<BlockPipe *>(overItem))
            updateLabel(bp->getValueString());
        else if (BlockItem *bi = dynamic_cast<BlockItem *>(overItem))
            updateLabel(bi->getDesc());
    }

    // Redraw temporary pipe
    if (line != nullptr) {
        QLineF newLine(line->line().p1(), mouseEvent->scenePos());
        line->setLine(newLine);
    }
    else
        QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void BlockScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button() != Qt::LeftButton)
        return;

    // Finalize drawing of pipe
    if (line != nullptr) {
        removeItem(line);
        delete line;
        line = nullptr;

        QGraphicsItem *overItem = itemAt(mouseEvent->scenePos(), viewParent->transform());
        if (overItem) {
            BlockSlotIn *bs = dynamic_cast<BlockSlotIn *>(overItem);
            if (bs && !bs->getPipe() && bs->getType() == startingSlot->getType()) {
                // Add new pipe
                BlockPipe *p = new BlockPipe(this, startingSlot, bs);
                if (!compute(true)) {
                    // loop detected!
                    delete p;
                    QMessageBox msgBox;
                    msgBox.setText("Loop detected - connection not created");
                    msgBox.exec();
                } else {
                    addItem(p);
                }
            }
        }
    }

    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

void BlockScene::clearScene()
{
    foreach (auto block, blocks) {
        delete block;
    }
    blocks.clear();
}

void BlockScene::loadFromFile(QString filename)
{
    clearScene();

}

void BlockScene::saveToFile(QString filename)
{
    QFile file(filename);
    file.open(QFile::WriteOnly | QFile::Text);

    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("schema");

    writer.writeStartElement("blocks");
    foreach (auto block, blocks) {
        writer.writeStartElement("block");
        writer.writeAttribute("id", QString::number(blocks.indexOf(block)));
        writer.writeAttribute("type", block->getName());
        writer.writeAttribute("posx", QString::number(block->scenePos().rx()));
        writer.writeAttribute("posy", QString::number(block->scenePos().ry()));

        foreach (auto slot, block->out_slots) {
            if (!slot->getPipe())
                continue;
            writer.writeStartElement("pipe");
            writer.writeAttribute("srcblock", QString::number(blocks.indexOf(block)));
            writer.writeAttribute("srcslot", QString::number(block->out_slots.indexOf(slot)));
            BlockItem *tgtBlock = slot->getPipe()->inSlot->getBlock();
            writer.writeAttribute("tgtblock", QString::number(blocks.indexOf(tgtBlock)));
            writer.writeAttribute("tgtslot", QString::number(tgtBlock->in_slots.indexOf(
                                      static_cast<BlockSlotIn *>(slot->getPipe()->inSlot))));
            writer.writeEndElement(); // pipe
        }

        writer.writeEndElement(); // block
    }
    writer.writeEndElement(); // blocks

    writer.writeEndElement(); // schema
    writer.writeEndDocument();

    file.close();
}

void BlockScene::removeSelected()
{
    computeAbort();
    foreach (QGraphicsItem *item, selectedItems()) {
        delete item;
    }
}

bool BlockScene::compute(bool fake)
{
    if (!computeInit(fake))
        return false;

    while (computeStep(fake));

    return computeWait.isEmpty();
}

bool BlockScene::computeInit(bool fake)
{
    computeWait.clear();
    computeReady.clear();
    computingNow = nullptr;

    foreach (BlockItem *item, blocks) {
        item->computed = false;
        if (!fake && !item->askForInput())
            return false;
    }

    computeWait << blocks;
    computeInProgress = true;

    return true;
}

bool BlockScene::computeStep(bool fake)
{
    QList<BlockItem *> wait_tmp;

    if (!computeInProgress)
        return false;

    if (computingNow) {
        computingNow->setHighlight(false);
        computingNow = nullptr;
    }

    foreach (BlockItem *item, computeWait) {
        if (item->isReady())
            computeReady.append(item);
        else
            wait_tmp.append(item);
    }
    computeWait = wait_tmp;

    if (computeReady.isEmpty()) {
        computeInProgress = false;
        return false;
    }

    computingNow = computeReady.takeFirst();
    computingNow->setHighlight(true);
    if (!fake)
        computingNow->compute();
    computingNow->computed = true;

    return true;
}

void BlockScene::computeAbort()
{
    if (!computeInProgress)
        return;

    computeInProgress = false;
    if (computingNow) {
        computingNow->setHighlight(false);
        computingNow = nullptr;
    }
}
