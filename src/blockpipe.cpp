/*!
 * \file blockpipe.cpp
 * \brief Source file for BlockPipe class
 * \author Jiri Vozar
 * \author Vaclav Dolezal
 */

#include "blockpipe.h"

BlockPipe::BlockPipe(BlockScene *parent, BlockSlot *outSlot, BlockSlot *inSlot)
{
    this->parent_scene = parent;
    parent_scene->addItem(this);

    this->outSlot = outSlot;
    this->inSlot = inSlot;
    outSlot->setPipe(this);
    inSlot->setPipe(this);

    setLine(QLineF(outSlot->scenePos(), inSlot->scenePos()));
    setPen(QPen(Qt::black, 2));
    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

void BlockPipe::updatePosition()
{
    setLine(QLineF(outSlot->scenePos(), inSlot->scenePos()));
}

QMap<QString, double> *BlockPipe::getData()
{
    if (!outSlot)
        return nullptr;
    return outSlot->getData();
}

BlockPipe::~BlockPipe()
{
    outSlot->setPipe(nullptr);
    inSlot->setPipe(nullptr);
    parent_scene->removeItem(this);
}

QString BlockPipe::getValueString()
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
