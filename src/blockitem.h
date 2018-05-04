#ifndef BLOCKITEM_H
#define BLOCKITEM_H

#include <QGraphicsPixmapItem>
#include <QList>

#include "blockscene.h"
#include "blockslot.h"

class BlockScene;
class BlockSlot;
class BlockSlotIn;
class BlockSlotOut;

class BlockItem : public QGraphicsRectItem
{
public:
    BlockItem(BlockScene *parent, qreal x, qreal y);
    ~BlockItem();

    void setHighlight(bool value);
    virtual void compute() { return; }

    bool isReady();
    bool askForInput() {return true;}

    bool computed;

    QList<BlockSlotIn *> in_slots;
    QList<BlockSlotOut *> out_slots;

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

private:
    BlockScene *parent_scene;
};

class BlockItem_abs3 : public BlockItem
{
public:
    BlockItem_abs3(BlockScene *parent, qreal x, qreal y);

    virtual void compute() override;
};

class BlockItem_vec3 : public BlockItem
{
public:
    BlockItem_vec3(BlockScene *parent, qreal x, qreal y);

    virtual void compute() override;
};

class BlockItem_num3 : public BlockItem
{
public:
    BlockItem_num3(BlockScene *parent, qreal x, qreal y);

    virtual void compute() override;
};

class BlockItem_abs2 : public BlockItem
{
public:
    BlockItem_abs2(BlockScene *parent, qreal x, qreal y);

    virtual void compute() override;
};

class BlockItem_vec2 : public BlockItem
{
public:
    BlockItem_vec2(BlockScene *parent, qreal x, qreal y);

    virtual void compute() override;
};

class BlockItem_num2 : public BlockItem
{
public:
    BlockItem_num2(BlockScene *parent, qreal x, qreal y);

    virtual void compute() override;
};

#endif // BLOCKITEM_H
