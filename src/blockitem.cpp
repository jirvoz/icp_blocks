#include "blockitem.h"
#include "datacontainer.h"

BlockItem::BlockItem(BlockScene *parent, qreal x, qreal y)
{
    parent_scene = parent;
    parent_scene->addItem(this);
    setRect(0, 0, 100, 100);
    setPos(x, y);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

    // Slots
    in_slots.append(new BlockSlotIn(this, 0, 10, DataType::NUMBER));
    in_slots.append(new BlockSlotIn(this, 0, 80, DataType::NUMBER));
    out_slots.append(new BlockSlotOut(this, 90, 45, DataType::VEC2));
    foreach (auto sl, in_slots) {
        sl->setParentItem(this);
    }
    foreach (auto sl, out_slots) {
        sl->setParentItem(this);
    }
}

BlockItem::~BlockItem()
{

}
