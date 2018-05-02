#include "blockslotout.h"

BlockSlotOut::BlockSlotOut(BlockItem *parent, qreal x, qreal y, DataType type) :
    BlockSlot(parent, x, y),
    valueData(type)
{}

bool BlockSlotOut::dataValid()
{
    return true;
}

DataType BlockSlotOut::getType()
{
    return valueData.getType();
}

QMap<QString, double> *BlockSlotOut::getData()
{
    return valueData.getData();
}
