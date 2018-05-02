#ifndef BLOCKSLOT_H
#define BLOCKSLOT_H

#include <QGraphicsPixmapItem>

#include "blockitem.h"
#include "blockpipe.h"
#include "datacontainer.h"

class BlockItem;
class BlockPipe;

class BlockSlot : public QGraphicsRectItem
{
public:
    BlockSlot(BlockItem *parent, qreal x, qreal y);

    void setPipe(BlockPipe *pipe) { this->pipe = pipe; }

    virtual bool dataValid() = 0;
    virtual QMap<QString, double> *getData() = 0;
    virtual DataType getType() = 0;

private:
    BlockItem *parent_block;
    BlockPipe *pipe;
};

#endif // BLOCKSLOT_H
