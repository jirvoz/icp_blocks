#ifndef BLOCKSLOTOUT_H
#define BLOCKSLOTOUT_H

#include "blockslot.h"
#include "datacontainer.h"

class BlockSlotOut : public BlockSlot
{
public:
    BlockSlotOut(BlockItem *parent, qreal x, qreal y, DataType type);
private:
	DataContainer valueData;
};

#endif // BLOCKSLOTOUT_H
