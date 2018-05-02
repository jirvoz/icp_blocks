#ifndef BLOCKSCENE_H
#define BLOCKSCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QList>

#include "blockitem.h"
#include "blockpipe.h"

class BlockItem;
class BlockPipe;

class BlockScene : public QGraphicsScene
{
    Q_OBJECT

public:
    BlockScene(QGraphicsView *parent);

    void clearScene(); // for "New" button to remove all entities
    void loadFromFile(QString filename);
    void saveToFile(QString filename);
    void removeSelected();
    void setDrawPipe(bool value) { drawPipe = value; }
    void addBlock();

signals:
    void updateLabel(QString text);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

private:
    QList<BlockItem *> blocks;
    QList<BlockPipe *> pipes;
    QGraphicsLineItem *line;
    QGraphicsView *viewParent;
    bool drawPipe;
};

#endif // BLOCKSCENE_H
