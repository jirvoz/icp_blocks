#include "blockslotin.h"

BlockSlotIn::BlockSlotIn(BlockItem *parent, qreal x, qreal y, DataType type) :
    BlockSlot(parent, x, y),
    valueType(type),
    valueData(nullptr)
{}
