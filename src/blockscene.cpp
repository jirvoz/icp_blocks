#include <QGraphicsSceneMouseEvent>

#include "blockscene.h"

BlockScene::BlockScene()
{
    blocks.append(new BlockItem(this, 10, 20));
    blocks.append(new BlockItem(this, 210, 150));
    pipes.append(new BlockPipe(this, blocks[0]->out_slots[0], blocks[1]->in_slots[0]));
}

void BlockScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button() != Qt::LeftButton)
        return;

    QGraphicsScene::mousePressEvent(mouseEvent);
}

void BlockScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button() != Qt::LeftButton)
        return;

    foreach (auto pipe, pipes) {
        pipe->updatePosition();
    }

    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

void clearScene()
{

}

void loadFromFile(QString filename)
{
    clearScene();

}

void saveToFile(QString filename)
{

}
