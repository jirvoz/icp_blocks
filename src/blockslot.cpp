#include "blockslot.h"

BlockSlot::BlockSlot(BlockItem *parent, qreal x, qreal y)
{
    pipe = nullptr;
    parent_block = parent;
    setRect(-5, -5, 10, 10);
    setPos(x + 5, y + 5);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

QString BlockSlot::getValueString()
{
    QString ret;
    QMapIterator<QString, double> it(*getData());

    while (it.hasNext()) {
        ret.append(QString("%1: %2").arg(it.key()).arg(it.value()));
    }
    return ret;
}
