/*!
 * \file blockscene.h
 * \brief Header file for BlockScene class
 * \author Jiri Vozar
 * \author Vaclav Dolezal
 */

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
     * \brief Add new block to scene
     * Add new block to scene wit type specified through template
     */
    template<class T> void createBlock()
    { blocks.append(new T(this, std::rand() % 101 - 50, std::rand() % 101 - 50)); }

    /*!
     * \brief Computes all blocks
     * \param fake check for loops only
     * \return true if OK
     */
    bool compute(bool fake = false);

    /*!
     * \brief Starts computation
     * \param fake fake computation
     * \return true if OK
     */
    bool computeInit(bool fake = false);

    /*!
     * \brief Perform one computation
     * \param fake fake computation
     * \return false if there is no computation to be performed
     */
    bool computeStep(bool fake = false);

    /*!
     * \brief Aborts computation
     */
    void computeAbort();

    /*!
     * \brief Check if computation is in progress
     * \return true if computation is running
     */
    bool isComputing() {return computeInProgress;}

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

    QGraphicsLineItem *line;    //!< temporary line when drawin pipe
    BlockSlot *startingSlot;     //!< slot where drawn line begins

    bool computeInProgress; //!< Compute is in progress
    QList<BlockItem *> computeWait; //!< Queue of blocks waiting for input
    QList<BlockItem *> computeReady; //!< Queue of ready blocks
    BlockItem *computingNow; //!< Block which is computed now
};

#endif // BLOCKSCENE_H
