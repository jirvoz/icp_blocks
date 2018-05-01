#ifndef DATACONTAINER_H
#define DATACONTAINER_H

#include <string>
#include <map>

enum DataType {
    NUMBER,
    VEC2,
    VEC3
};

class DataContainer
{
    DataType type;
    std::map<std::string, double> dict;
public:
    DataContainer(DataType type);
};

#endif // DATACONTAINER_H
