#include "blockpipe.h"

BlockPipe::BlockPipe(BlockScene *parent, BlockSlot *outSlot, BlockSlot *inSlot)
{
    this->parent_scene = parent;
    parent_scene->addItem(this);

    this->outSlot = outSlot;
    this->inSlot = inSlot;
    outSlot->setPipe(this);
    inSlot->setPipe(this);

    setLine(QLineF(outSlot->scenePos(), inSlot->scenePos()));
    setPen(QPen(Qt::black, 2));
    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

void BlockPipe::updatePosition()
{
    setLine(QLineF(outSlot->scenePos(), inSlot->scenePos()));
}

QMap<QString, double> *BlockPipe::getData()
{
    if (!outSlot)
		return nullptr;
	return outSlot->getData();
}

BlockPipe::~BlockPipe()
{

}
