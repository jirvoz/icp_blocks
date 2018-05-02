#include "blockslotin.h"

BlockSlotIn::BlockSlotIn(BlockItem *parent, qreal x, qreal y, DataType type) :
    BlockSlot(parent, x, y),
    valueType(type),
    valueData(nullptr)
{}

bool BlockSlotIn::dataValid()
{
    return valueData && valueData->typeMatch(valueType);
}

DataType BlockSlotIn::getType()
{
    return valueType;
}

QMap<QString, double> *BlockSlotIn::getData()
{
    return valueData ? valueData->getData() : nullptr;
}
