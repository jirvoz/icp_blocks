/*!
 * \file blockslot.h
 * \brief Header file for BlockSlot class and its In and Out subclasses
 * \author Jiri Vozar
 * \author Vaclav Dolezal
 */

#ifndef BLOCKSLOT_H
#define BLOCKSLOT_H

#include <QGraphicsPixmapItem>

#include "blockitem.h"
#include "blockpipe.h"
#include "datacontainer.h"

class BlockItem;
class BlockPipe;

/**
 * \brief Input/Output slot of block
 */
class BlockSlot : public QGraphicsRectItem
{
public:
    BlockSlot(BlockItem *parent, qreal x, qreal y);

    /**
     * \brief Get associated pipe
     * \return associated pipe
     */
    BlockPipe *getPipe() const { return this->pipe; }
    /**
     * \brief Set associated pipe
     * \param pipe pipe to be associated with
     */
    void setPipe(BlockPipe *pipe) { this->pipe = pipe; }

    /**
     * \brief Get block in which this slot resides
     * \return parent block
     */
    BlockItem *getBlock() { return this->parent_block; }

    /**
     * \brief Get data value
     * \return QMap with data
     */
    virtual QMap<QString, double> *getData() = 0;
    /**
     * \brief Get data type
     * \return data type
     */
    virtual DataType getType() = 0;
    /**
     * \brief Get data value as string
     * \return string representation of data
     */
    QString getValueString();

private:
    BlockItem *parent_block;
    BlockPipe *pipe;
};

/**
 * \brief Input slot of block
 */
class BlockSlotIn : public BlockSlot
{
public:
    BlockSlotIn(BlockItem *parent, qreal x, qreal y, DataType type);
    DataType getType() override;

    /**
     * \brief Get data
     * \return QMap with data
     */
    QMap<QString, double> *getData() override;

    /**
     * \brief Check if input is ready
     * \return true if input is ready
     */
    bool isDataReady();

    /**
     * \brief Get map to be filled
     * \return QMap to be filled, NULL if pipe is connected
     */
    QMap<QString, double> *getInputMap();
private:
    DataType valueType;
    DataContainer valueData; //! < user input data
};

/**
 * \brief Output slot of block
 */
class BlockSlotOut : public BlockSlot
{
public:
    BlockSlotOut(BlockItem *parent, qreal x, qreal y, DataType type);
    DataType getType() override;
    QMap<QString, double> *getData() override;
private:
    DataContainer valueData;
};

#endif // BLOCKSLOT_H
