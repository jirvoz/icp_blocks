#include "blockscene.h"

BlockScene::BlockScene()
{
    QGraphicsRectItem *parent_r = new QGraphicsRectItem(0,0,100,100);
    QGraphicsRectItem *child_r = new QGraphicsRectItem(10,10,10,10);
    child_r->setParentItem(parent_r);
    addItem(parent_r);
    addItem(child_r);

    parent_r->setFlag(QGraphicsItem::ItemIsMovable, true);
    parent_r->setFlag(QGraphicsItem::ItemIsSelectable, true);
    parent_r->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    child_r->setFlag(QGraphicsItem::ItemIsMovable, true);
    child_r->setFlag(QGraphicsItem::ItemIsSelectable, true);
    child_r->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}
