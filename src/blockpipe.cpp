#include "blockpipe.h"

BlockPipe::BlockPipe(BlockScene *parent, BlockSlot *startSlot, BlockSlot *endSlot)
{
    this->parent_scene = parent;
    parent_scene->addItem(this);

    this->startSlot = startSlot;
    this->endSlot = endSlot;

    QLineF *lin = new QLineF(startSlot->scenePos(), endSlot->scenePos());
    setLine(100, 100, 500, 400);
    setLine(QLineF(startSlot->scenePos(), endSlot->scenePos()));
    qCritical("Pokus.");
}
