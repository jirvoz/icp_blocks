#include "datacontainer.h"

DataContainer::DataContainer(DataType type) : type(type)
{
    switch (type) {
    case NUMBER:
        dict.emplace("number", 0.);
        break;
    case VEC2:
        dict.emplace("x", 0.);
        dict.emplace("y", 0.);
        break;
    case VEC3:
        dict.emplace("x", 0.);
        dict.emplace("y", 0.);
        dict.emplace("z", 0.);
        break;
    default:
        break;
    }
}
