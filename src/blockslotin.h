#ifndef BLOCKSLOTIN_H
#define BLOCKSLOTIN_H

#include "blockslot.h"
#include "datacontainer.h"

class BlockSlotIn : public BlockSlot
{
	DataType type;
	DataContainer *data;
public:
    BlockSlotIn(BlockItem *parent, qreal x, qreal y, DataType type);
};

#endif // BLOCKSLOTIN_H
