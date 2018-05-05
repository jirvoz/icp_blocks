/*!
 * \file blockitem.cpp
 * \brief Source file for BlockItem class and its subclasses
 * \author Jiri Vozar
 * \author Vaclav Dolezal
 */

#include <cmath>

#include "blockitem.h"
#include "datacontainer.h"
#include "inputdialog.h"

BlockItem::BlockItem(BlockScene *parent, qreal x, qreal y) : computed(false)
{
    parent_scene = parent;
    parent_scene->addItem(this);
    setRect(0, 0, 100, 100);
    setPos(x, y);
    setBrush(Qt::white);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

void BlockItem::setHighlight(bool value)
{
    if (value)
        setBrush(Qt::yellow);
    else
        setBrush(Qt::white);
}

bool BlockItem::askForInput()
{
    int i = 1;
    setHighlight(true);
    foreach (auto sl, in_slots) {
        auto map = sl->getInputMap();
        if (!map)
            continue;
        InputDialog dialog(map, QString("slot %1").arg(i), nullptr);
        if (dialog.exec() == QDialog::Rejected) {
            setHighlight(false);
            return false;
        }
        i++;
    }
    setHighlight(false);
    return true;
}

bool BlockItem::isReady()
{
    foreach (auto sl, in_slots) {
        if (!sl->isDataReady())
            return false;
    }
    return true;
}

void BlockItem::layoutSlots()
{
    qreal spacing, pos;
    qreal start = 10, end = 90, slot_size = 15;

    auto sz = in_slots.size();
    if (sz == 0) {
        // do nothing
    } else if (sz == 1) {
        in_slots[0]->setPos(slot_size/2, 50);
    } else {
        spacing = (end - start) / (sz - 1);
        pos = start;
        foreach (auto sl, in_slots) {
            sl->setPos(slot_size/2, pos);
            pos += spacing;
        }
    }

    sz = out_slots.size();
    if (sz == 0) {
        // do nothing
    } else if (sz == 1) {
        out_slots[0]->setPos(100 - (slot_size/2), 50);
    } else {
        spacing = (end - start) / (sz - 1);
        pos = start;
        foreach (auto sl, out_slots) {
            sl->setPos(100 - (slot_size/2), pos);
            pos += spacing;
        }
    }
}

BlockItem_abs3::BlockItem_abs3(BlockScene *parent, qreal x, qreal y):
    BlockItem(parent, x, y)
{
    // Slots
    in_slots.append(new BlockSlotIn(this, DataType::VEC3));
    out_slots.append(new BlockSlotOut(this, DataType::NUMBER));
    layoutSlots();
    foreach (auto sl, in_slots) {
        sl->setParentItem(this);
    }
    foreach (auto sl, out_slots) {
        sl->setParentItem(this);
    }
}

void BlockItem_abs3::compute()
{
    auto &in_data = *in_slots[0]->getData();
    double x = in_data["x"];
    double y = in_data["y"];
    double z = in_data["z"];

    (*out_slots[0]->getData())["number"] = sqrt(x*x + y*y + z*z);
}

BlockItem_vec3::BlockItem_vec3(BlockScene *parent, qreal x, qreal y):
    BlockItem(parent, x, y)
{
    // Slots
    in_slots.append(new BlockSlotIn(this, DataType::NUMBER));
    in_slots.append(new BlockSlotIn(this, DataType::NUMBER));
    in_slots.append(new BlockSlotIn(this, DataType::NUMBER));
    out_slots.append(new BlockSlotOut(this, DataType::VEC3));
    layoutSlots();
    foreach (auto sl, in_slots) {
        sl->setParentItem(this);
    }
    foreach (auto sl, out_slots) {
        sl->setParentItem(this);
    }
}

void BlockItem_vec3::compute()
{
    auto &out_data = *out_slots[0]->getData();

    out_data["x"] = in_slots[0]->getData()->value("number");
    out_data["y"] = in_slots[1]->getData()->value("number");
    out_data["z"] = in_slots[2]->getData()->value("number");
}

BlockItem_num3::BlockItem_num3(BlockScene *parent, qreal x, qreal y):
    BlockItem(parent, x, y)
{
    // Slots
    in_slots.append(new BlockSlotIn(this, DataType::VEC3));
    out_slots.append(new BlockSlotOut(this, DataType::NUMBER));
    out_slots.append(new BlockSlotOut(this, DataType::NUMBER));
    out_slots.append(new BlockSlotOut(this, DataType::NUMBER));
    layoutSlots();
    foreach (auto sl, in_slots) {
        sl->setParentItem(this);
    }
    foreach (auto sl, out_slots) {
        sl->setParentItem(this);
    }
}

void BlockItem_num3::compute()
{
    auto &in_data = *in_slots[0]->getData();

    (*out_slots[0]->getData())["number"] = in_data["x"];
    (*out_slots[1]->getData())["number"] = in_data["y"];
    (*out_slots[2]->getData())["number"] = in_data["z"];
}

BlockItem_abs2::BlockItem_abs2(BlockScene *parent, qreal x, qreal y):
    BlockItem(parent, x, y)
{
    // Slots
    in_slots.append(new BlockSlotIn(this, DataType::VEC2));
    out_slots.append(new BlockSlotOut(this, DataType::NUMBER));
    layoutSlots();
    foreach (auto sl, in_slots) {
        sl->setParentItem(this);
    }
    foreach (auto sl, out_slots) {
        sl->setParentItem(this);
    }
}

void BlockItem_abs2::compute()
{
    auto &in_data = *in_slots[0]->getData();
    double x = in_data["x"];
    double y = in_data["y"];

    (*out_slots[0]->getData())["number"] = sqrt(x*x + y*y);
}

BlockItem_vec2::BlockItem_vec2(BlockScene *parent, qreal x, qreal y):
    BlockItem(parent, x, y)
{
    // Slots
    in_slots.append(new BlockSlotIn(this, DataType::NUMBER));
    in_slots.append(new BlockSlotIn(this, DataType::NUMBER));
    out_slots.append(new BlockSlotOut(this, DataType::VEC2));
    layoutSlots();
    foreach (auto sl, in_slots) {
        sl->setParentItem(this);
    }
    foreach (auto sl, out_slots) {
        sl->setParentItem(this);
    }
}

void BlockItem_vec2::compute()
{
    auto &out_data = *out_slots[0]->getData();

    out_data["x"] = in_slots[0]->getData()->value("number");
    out_data["y"] = in_slots[1]->getData()->value("number");
}

BlockItem_num2::BlockItem_num2(BlockScene *parent, qreal x, qreal y):
    BlockItem(parent, x, y)
{
    // Slots
    in_slots.append(new BlockSlotIn(this, DataType::VEC2));
    out_slots.append(new BlockSlotOut(this, DataType::NUMBER));
    out_slots.append(new BlockSlotOut(this, DataType::NUMBER));
    layoutSlots();
    foreach (auto sl, in_slots) {
        sl->setParentItem(this);
    }
    foreach (auto sl, out_slots) {
        sl->setParentItem(this);
    }
}

void BlockItem_num2::compute()
{
    auto &in_data = *in_slots[0]->getData();

    (*out_slots[0]->getData())["number"] = in_data["x"];
    (*out_slots[1]->getData())["number"] = in_data["y"];
}

QVariant BlockItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == QGraphicsItem::ItemPositionChange) {
        foreach (auto sl, in_slots) {
        if (sl->getPipe())
            sl->getPipe()->updatePosition();
        }
        foreach (auto sl, out_slots) {
        if (sl->getPipe())
            sl->getPipe()->updatePosition();
        }
    }

    return value;
}

BlockItem::~BlockItem()
{
    foreach (auto sl, in_slots) {
        if (sl->getPipe())
            delete sl->getPipe();
    }
    foreach (auto sl, out_slots) {
        if (sl->getPipe())
            delete sl->getPipe();
    }

    parent_scene->removeItem(this);
    parent_scene->blocks.removeOne(this);
}
