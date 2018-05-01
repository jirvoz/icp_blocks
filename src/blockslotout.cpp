#include "blockslotout.h"

BlockSlotOut::BlockSlotOut(BlockItem *parent, qreal x, qreal y, DataType type) :
    BlockSlot(parent, x, y),
    data(type)
{}

