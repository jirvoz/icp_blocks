#ifndef BLOCKSLOTOUT_H
#define BLOCKSLOTOUT_H

#include "blockslot.h"
#include "datacontainer.h"

class BlockSlotOut : public BlockSlot
{
	DataContainer data;
public:
    BlockSlotOut(BlockItem *parent, qreal x, qreal y, DataType type);
};

#endif // BLOCKSLOTOUT_H
