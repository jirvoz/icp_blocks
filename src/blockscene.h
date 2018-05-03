#ifndef BLOCKSCENE_H
#define BLOCKSCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QList>

#include "blockitem.h"
#include "blockpipe.h"
#include "datacontainer.h"

class BlockItem;
class BlockPipe;

/*!
* \brief Main scene class for handling drawable items.
* Contains lists of blocks with pipes and manages them.
* Is instance of QGraphicsScene object which is then
* displayed using QGraphicsView widget in GUI.
*/
class BlockScene : public QGraphicsScene
{
    Q_OBJECT

public:
    /*!
     * \brief Scene constructor.
     * \param parent QGraphicsView widget, which draws the scene
     */
    BlockScene(QGraphicsView *parent);

    //! \brief Scene destructor
    ~BlockScene();

    //! \brief Remove all objects from scene.
    void clearScene(); // for "New" button to remove all entities

    /*!
     * \brief Loads scene content from file.
     * \param filename path to the file
     */

    void loadFromFile(QString filename);
    /*!
     * \brief Saves scene content to file.
     * \param filename path to the file
     */

    void saveToFile(QString filename);

    //! \brief Removes all selected objects from scene
    void removeSelected();

    /*!
     * \brief Switches between drawing pipes and moving blocks
     * \param value true if pipes will be drawn
     */
    void setDrawPipe(bool value) { drawPipe = value; }

    //! \brief Adds generic block
    void addBlock();

    QList<BlockItem *> blocks;  //!< list of blocks in schema

signals:
    /*!
     * \brief Sends information text to be displayed in GUI.
     * \param text text to be displayed
     */
    void updateLabel(QString text);

protected:
    /*!
     * \brief Overriden method mousePressEvent from inherited class
     * \param mouseEvent mouse data
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

    /*!
     * \brief Overriden method mouseMoveEvent from inherited class
     * \param mouseEvent mouse data
     */
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

    /*!
     * \brief Overriden method mouseReleaseEvent from inherited class
     * \param mouseEvent mouse data
     */
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

private:
    QGraphicsView *viewParent;  //!< QGraphicsView the scene is drawn on

    bool drawPipe;              //!< true if pipes can be drawn
    QGraphicsLineItem *line;    //!< temporary line when drawin pipe
    BlockSlot *startingSlot;     //!< slot where drawn line begins
};

#endif // BLOCKSCENE_H
