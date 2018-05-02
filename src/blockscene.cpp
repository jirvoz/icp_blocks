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
        line = new QGraphicsLineItem(QLineF(mouseEvent->scenePos(),
                    mouseEvent->scenePos()));
        addItem(line);
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

    /*if (mouseEvent->button() != Qt::LeftButton) {
        QGraphicsScene::mouseMoveEvent(mouseEvent);
        return;
    }*/

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
