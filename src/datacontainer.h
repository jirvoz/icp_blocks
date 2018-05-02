#ifndef DATACONTAINER_H
#define DATACONTAINER_H

#include <QMap>
#include <QString>

enum DataType {
    NUMBER,
    VEC2,
    VEC3
};

class DataContainer
{
    DataType type;
    QMap<QString, double> dict;
public:
    DataContainer(DataType type);
};

#endif // DATACONTAINER_H
