#ifndef BLOCKSLOTIN_H
#define BLOCKSLOTIN_H

#include "blockslot.h"

class BlockSlotIn : public BlockSlot
{
public:
    BlockSlotIn(BlockItem *parent, qreal x, qreal y, DataType type);
    bool dataValid() override;
    DataType getType() override;
    QMap<QString, double> *getData() override;
private:
    DataType valueType;
    DataContainer *valueData;
};

#endif // BLOCKSLOTIN_H
