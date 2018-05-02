#ifndef BLOCKITEM_H
#define BLOCKITEM_H

#include <QGraphicsPixmapItem>
#include <QList>

#include "blockslot.h"
#include "blockscene.h"

class BlockScene;
class BlockSlot;

class BlockItem : public QGraphicsRectItem
{
public:
    BlockItem(BlockScene *parent, qreal x, qreal y);

    virtual void Compute() { return; }

    QList<BlockSlot *> in_slots;
    QList<BlockSlot *> out_slots;

private:
    BlockScene *parent_scene;
};

#endif // BLOCKITEM_H
