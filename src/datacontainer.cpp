/*!
 * \file datacontainer.cpp
 * \brief Source file for DataContainer class
 * \author Jiri Vozar
 * \author Vaclav Dolezal
 */

#include "datacontainer.h"

DataContainer::DataContainer(DataType type) : type(type)
{
    switch (type) {
    case NUMBER:
        dict.insert("number", 0.);
        break;
    case VEC2:
        dict.insert("x", 0.);
        dict.insert("y", 0.);
        break;
    case VEC3:
        dict.insert("x", 0.);
        dict.insert("y", 0.);
        dict.insert("z", 0.);
        break;
    default:
        break;
    }
}

QMap<QString, double> *DataContainer::getData()
{
    return &dict;
}

DataType DataContainer::getType()
{
    return type;
}
