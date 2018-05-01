#ifndef BLOCKSLOT_H
#define BLOCKSLOT_H

#include <QGraphicsPixmapItem>

#include "blockitem.h"
#include "blockpipe.h"

class BlockItem;
class BlockPipe;

class BlockSlot : public QGraphicsRectItem
{
public:
    BlockSlot(BlockItem *parent, qreal x, qreal y);

    void setPipe(BlockPipe *pipe) { this->pipe = pipe; }

private:
    BlockItem *parent_block;
    BlockPipe *pipe;
};

#endif // BLOCKSLOT_H
