#include "blockpipe.h"

BlockPipe::BlockPipe(BlockScene *parent, BlockSlot *startSlot, BlockSlot *endSlot)
{
    this->parent_scene = parent;
    parent_scene->addItem(this);

    this->startSlot = startSlot;
    this->endSlot = endSlot;
    startSlot->setPipe(this);
    endSlot->setPipe(this);

    setLine(QLineF(startSlot->scenePos(), endSlot->scenePos()));
    setPen(QPen(Qt::black, 2));
    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

void BlockPipe::updatePosition()
{
    setLine(QLineF(startSlot->scenePos(), endSlot->scenePos()));
}
