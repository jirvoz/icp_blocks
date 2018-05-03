#include <QGraphicsSceneMouseEvent>

#include "blockscene.h"

BlockScene::BlockScene(QGraphicsView *parent)
    : QGraphicsScene(parent)
{
    viewParent = parent;
    drawPipe = false;
    line = nullptr;
    blocks.append(new BlockItem(this, 10, 20));
    blocks.append(new BlockItem(this, 210, 150));
    pipes.append(new BlockPipe(this, blocks[0]->out_slots[0], blocks[1]->in_slots[0]));
}

void BlockScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button() != Qt::LeftButton)
        return;

    // Start drawing of pipe
    if (drawPipe) {
        QGraphicsItem *overItem = itemAt(mouseEvent->scenePos(), viewParent->transform());
        if (overItem) {
            BlockSlotOut *bs = dynamic_cast<BlockSlotOut *>(overItem);
            if (bs) {
                startingSlot = bs;
                line = new QGraphicsLineItem(QLineF(mouseEvent->scenePos(),
                        mouseEvent->scenePos()));
                addItem(line);
            }
        }
    }

    QGraphicsScene::mousePressEvent(mouseEvent);
}

void BlockScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    // Show values of slot when hovering over
    QGraphicsItem *overItem = itemAt(mouseEvent->scenePos(), viewParent->transform());
    if (overItem) {
        BlockSlot *bs = dynamic_cast<BlockSlot *>(overItem);
        if (bs)
            updateLabel(bs->getValueString());
    }

    // Redraw temporary pipe
    if (drawPipe && line != nullptr) {
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

    // Update pipes positions
    foreach (auto pipe, pipes) {
        pipe->updatePosition();
    }

    // Finalize drawing of pipe
    if (drawPipe && line != nullptr) {
        removeItem(line);
        delete line;
        line = nullptr;

        QGraphicsItem *overItem = itemAt(mouseEvent->scenePos(), viewParent->transform());
        if (overItem) {
            BlockSlotIn *bs = dynamic_cast<BlockSlotIn *>(overItem);
            if (bs && bs->getType() == startingSlot->getType()) {
                // Add new pipe
                BlockPipe *p = new BlockPipe(this, startingSlot, bs);
                addItem(p);
            }
        }
    }

    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

void BlockScene::clearScene()
{
    foreach (auto pipe, pipes) {
        removeItem(pipe);
    }
    pipes.clear();

    foreach (auto block, blocks) {
        removeItem(block);
    }
    blocks.clear();
}

void BlockScene::loadFromFile(QString filename)
{
    clearScene();

}

void BlockScene::saveToFile(QString filename)
{

}

void BlockScene::removeSelected()
{
    //foreach (QGraphicsItem item, selectedItems()) {

    //}
}

void BlockScene::addBlock()
{
    blocks.append(new BlockItem(this, std::rand() % 101 - 50,
                                std::rand() % 101 - 50));
}
