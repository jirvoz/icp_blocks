/*!
 * \file blockitem.h
 * \brief Header file for BlockItem class and its subclasses
 * \author Jiri Vozar
 * \author Vaclav Dolezal
 */

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

/**
 * \brief Computation block
 */
class BlockItem : public QGraphicsRectItem
{
public:
    BlockItem(BlockScene *parent, qreal x, qreal y);
    ~BlockItem();

    /**
     * \brief Get name of block
     * \return name of block
     */
    virtual QString getName() { return QString();}

    /**
     * \brief Get short description of block
     * \return description of block
     */
    virtual QString getDesc()  { return QString();}

    /**
     * \brief Sets whether block is highlighted
     * \param value if true, block will be highlighted
     */
    void setHighlight(bool value);

    /// \brief Computes block
    virtual void compute() { return; }

    bool isReady();
    bool askForInput();

    bool computed;

    QList<BlockSlotIn *> in_slots;
    QList<BlockSlotOut *> out_slots;

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

    /// \brief Lays out slots
    void layoutSlots();

private:
    BlockScene *parent_scene;
};

/**
 * \brief Computation block: absolute value of 3D vector
 */
class BlockItem_abs3 : public BlockItem
{
public:
    BlockItem_abs3(BlockScene *parent, qreal x, qreal y);

    virtual void compute() override;
    virtual QString getName() override { return QString("ABS3");}
    virtual QString getDesc() override { return QString("Absolute value of 3D vector");}
};

/**
 * \brief Computation block: 3D vector from numbers
 */
class BlockItem_vec3 : public BlockItem
{
public:
    BlockItem_vec3(BlockScene *parent, qreal x, qreal y);
    virtual QString getName() override { return QString("VEC3");}
    virtual QString getDesc() override { return QString("Assembles 3D vector from numbers");}

    virtual void compute() override;
};

/**
 * \brief Computation block: 3D vector to numbers
 */
class BlockItem_num3 : public BlockItem
{
public:
    BlockItem_num3(BlockScene *parent, qreal x, qreal y);
    virtual QString getName() override { return QString("NUM3");}
    virtual QString getDesc() override { return QString("Disassembles 3D vector to numbers");}

    virtual void compute() override;
};

/**
 * \brief Computation block: absolute value of 2D vector
 */
class BlockItem_abs2 : public BlockItem
{
public:
    BlockItem_abs2(BlockScene *parent, qreal x, qreal y);
    virtual QString getName() override { return QString("ABS2");}
    virtual QString getDesc() override { return QString("Absolute value of 2D vector");}

    virtual void compute() override;
};

/**
 * \brief Computation block: 2D vector from numbers
 */
class BlockItem_vec2 : public BlockItem
{
public:
    BlockItem_vec2(BlockScene *parent, qreal x, qreal y);
    virtual QString getName() override { return QString("VEC2");}
    virtual QString getDesc() override { return QString("Assembles 2D vector from numbers");}

    virtual void compute() override;
};

/**
 * \brief Computation block: 2D vector to numbers
 */
class BlockItem_num2 : public BlockItem
{
public:
    BlockItem_num2(BlockScene *parent, qreal x, qreal y);
    virtual QString getName() override { return QString("NUM2");}
    virtual QString getDesc() override { return QString("Disassembles 2D vector to numbers");}

    virtual void compute() override;
};

#endif // BLOCKITEM_H
