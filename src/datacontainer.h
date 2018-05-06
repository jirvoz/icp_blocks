/*!
 * \file datacontainer.h
 * \brief Header file for DataContainer class
 * \author Jiri Vozar
 * \author Vaclav Dolezal
 */

#ifndef DATACONTAINER_H
#define DATACONTAINER_H

#include <QMap>
#include <QString>

enum DataType {
    NUMBER, ///< scalar number
    VEC2, ///< 2D vector
    VEC3 ///< 3D vector
};

/// \brief Data container for computation blocks
class DataContainer
{
public:
    /**
     * \brief Constructor of DataContainer
     * \param type type of data
     */
    DataContainer(DataType type);

    /**
     * \brief Get data
     * \return dictionary with data
     */
    QMap<QString, double> *getData();
    /**
     * \brief Get type
     * \return type of data
     */
    DataType getType();
private:
    /// \brief Type of data
    DataType type;
    /// \brief Dictionary with data
    QMap<QString, double> dict;
};

#endif // DATACONTAINER_H
