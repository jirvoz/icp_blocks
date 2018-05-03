#ifndef BLOCKPIPE_H
#define BLOCKPIPE_H

#include <QGraphicsPixmapItem>

#include "blockscene.h"
#include "blockslot.h"

class BlockScene;
class BlockSlot;

/*!
 * \brief Pipe class for connecting blocks.
 */
class BlockPipe : public QGraphicsLineItem
{
public:
    /*!
     * \brief Pipe constructor.
     * \param parent scene object the pipe is drawn on
     * \param outSlot output slot of a block providing data
     * \param inSlot input slot of a block for delivering data
     */
    BlockPipe(BlockScene *parent, BlockSlot *outSlot, BlockSlot *inSlot);

    //! \brief Pipe destructor.
    ~BlockPipe();

    //! \brief Update pipe position when moving attached block.
    void updatePosition();

private:
    BlockScene *parent_scene;  //!< Parent scene object the pipe is drawn on.
    BlockSlot *outSlot;        //!< Output slot of a block providing data
    BlockSlot *inSlot;         //!< Input slot of a block for delivering data
};

#endif // BLOCKPIPE_H
