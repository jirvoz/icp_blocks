#ifndef BLOCKITEM_H
#define BLOCKITEM_H

#include <QGraphicsPixmapItem>
#include <QList>

#include "blockscene.h"
#include "blockslot.h"
#include "blockslotin.h"
#include "blockslotout.h"

class BlockScene;
class BlockSlot;
class BlockSlotIn;
class BlockSlotOut;

class BlockItem : public QGraphicsRectItem
{
public:
    BlockItem(BlockScene *parent, qreal x, qreal y);
    ~BlockItem();

    virtual void compute() { return; }

    QList<BlockSlotIn *> in_slots;
    QList<BlockSlotOut *> out_slots;

private:
    BlockScene *parent_scene;
};

#endif // BLOCKITEM_H
