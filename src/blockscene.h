#ifndef BLOCKSCENE_H
#define BLOCKSCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QList>

#include "blockitem.h"

class BlockItem;

class BlockScene : public QGraphicsScene
{
    Q_OBJECT

public:
    BlockScene();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    //void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    //void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

private:
    QList<BlockItem *> blocks;
};

#endif // BLOCKSCENE_H
