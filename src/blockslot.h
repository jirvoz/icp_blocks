#ifndef BLOCKSLOT_H
#define BLOCKSLOT_H

#include <QGraphicsPixmapItem>

#include "blockitem.h"
#include "blockpipe.h"
#include "datacontainer.h"

class BlockItem;
class BlockPipe;

class BlockSlot : public QGraphicsRectItem
{
public:
    BlockSlot(BlockItem *parent, qreal x, qreal y);

    BlockPipe *getPipe() const { return this->pipe; }
    void setPipe(BlockPipe *pipe) { this->pipe = pipe; }
    BlockPipe *getPipe() { return this->pipe; }
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
    QString getValueString();

private:
    BlockItem *parent_block;
    BlockPipe *pipe;
};

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
