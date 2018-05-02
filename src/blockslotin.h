#ifndef BLOCKSLOTIN_H
#define BLOCKSLOTIN_H

#include "blockslot.h"
#include "datacontainer.h"

class BlockSlotIn : public BlockSlot
{
public:
    BlockSlotIn(BlockItem *parent, qreal x, qreal y, DataType type);
private:
    DataType valueType;
    DataContainer *valueData;
};

#endif // BLOCKSLOTIN_H
