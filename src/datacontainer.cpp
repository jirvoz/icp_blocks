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

bool DataContainer::typeMatch(DataType t)
{
	return type == t;
}

QMap<QString, double> *DataContainer::getData()
{
	return &dict;
}

DataType DataContainer::getType()
{
	return type;
}
