#include "blockitem.h"
#include <QDebug>

BlockItem::BlockItem(BlockScene *parent, qreal x, qreal y)
{
    parent_scene = parent;
    parent_scene->addItem(this);
    setRect(x, y, 100, 100);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

    // Slots
    in_slots.append(new BlockSlot(this, x, y + 10));
    in_slots.append(new BlockSlot(this, x, y + 80));
    out_slots.append(new BlockSlot(this, x + 90, y + 45));
    foreach (auto sl, in_slots) {
        sl->setParentItem(this);
        parent_scene->addItem(sl);
    }
    foreach (auto sl, out_slots) {
        sl->setParentItem(this);
        parent_scene->addItem(sl);
    }
    qDebug() << "pokus";
}
