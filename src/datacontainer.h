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
public:
    DataContainer(DataType type);
private:
    DataType type;
    QMap<QString, double> dict;
};

#endif // DATACONTAINER_H
