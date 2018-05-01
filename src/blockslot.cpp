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
