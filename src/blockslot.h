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

    virtual QMap<QString, double> *getData() = 0;
    virtual DataType getType() = 0;
    QString getValueString();

private:
    BlockItem *parent_block;
    BlockPipe *pipe;
};

class BlockSlotIn : public BlockSlot
{
public:
    BlockSlotIn(BlockItem *parent, qreal x, qreal y, DataType type);
    DataType getType() override;
    QMap<QString, double> *getData() override;
private:
    DataType valueType;
    DataContainer *valueData;
};

class BlockSlotOut : public BlockSlot
{
public:
    BlockSlotOut(BlockItem *parent, qreal x, qreal y, DataType type);
    DataType getType() override;
    QMap<QString, double> *getData() override;
private:
    DataContainer valueData;
};

#endif // BLOCKSLOT_H
