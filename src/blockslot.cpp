#include "blockslot.h"

BlockSlot::BlockSlot(BlockItem *parent, qreal x, qreal y)
{
    parent_block = parent;
    setRect(x, y, 10, 10);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}
