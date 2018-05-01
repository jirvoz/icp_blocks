#ifndef BLOCKPIPE_H
#define BLOCKPIPE_H

#include <QGraphicsPixmapItem>

#include "blockscene.h"
#include "blockslot.h"

class BlockScene;
class BlockSlot;

class BlockPipe : public QGraphicsLineItem
{
public:
    BlockPipe(BlockScene *parent, BlockSlot *startSlot, BlockSlot *endSlot);

    void updatePosition();

private:
    BlockScene *parent_scene;
    BlockSlot *startSlot;
    BlockSlot *endSlot;
};

#endif // BLOCKPIPE_H
