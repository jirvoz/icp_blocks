/*!
 * \file blockslot.cpp
 * \brief Source file for BlockSlot class and its In and Out subclasses
 * \author Jiri Vozar
 * \author Vaclav Dolezal
 */

#include "blockslot.h"

BlockSlot::BlockSlot(BlockItem *parent)
{
    pipe = nullptr;
    parent_block = parent;
    setRect(-7.5, -7.5, 15, 15);
    setPos(0, 0);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

QString BlockSlot::getValueString()
{
    QString ret;
    auto *d = getData();
    if (!d)
        return QString("");

    QMapIterator<QString, double> it(*d);

    while (it.hasNext()) {
        it.next();
        ret.append(QString("%1: %2").arg(it.key()).arg(it.value()));
        if (it.hasNext())
            ret.append("; ");
    }
    return ret;
}

BlockSlotIn::BlockSlotIn(BlockItem *parent, DataType type) :
    BlockSlot(parent),
    valueType(type),
    valueData(type)
{}

DataType BlockSlotIn::getType()
{
    return valueType;
}

QMap<QString, double> *BlockSlotIn::getData()
{
    auto pipe = getPipe();
    if (!pipe)
        return valueData.getData();
    return pipe->getData();
}

QMap<QString, double> *BlockSlotIn::getInputMap()
{
    auto pipe = getPipe();
    if (pipe)
        return nullptr;
    return valueData.getData();
}

bool BlockSlotIn::isDataReady()
{
    auto pipe = getPipe();
    if (!pipe)
        return true;
    return pipe->outSlot->getBlock()->computed;
}

BlockSlotOut::BlockSlotOut(BlockItem *parent, DataType type) :
    BlockSlot(parent),
    valueData(type)
{}

DataType BlockSlotOut::getType()
{
    return valueData.getType();
}

QMap<QString, double> *BlockSlotOut::getData()
{
    return valueData.getData();
}
