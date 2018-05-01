#include "blockslotin.h"

BlockSlotIn::BlockSlotIn(BlockItem *parent, qreal x, qreal y, DataType type) :
    BlockSlot(parent, x, y),
    type(type),
    data(nullptr)
{}
