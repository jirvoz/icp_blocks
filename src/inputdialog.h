#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>

#include "datacontainer.h"

class InputDialog : public QDialog
{
public:
    InputDialog(QMap<QString, double> *data, QString slotName, QWidget *parent);

private:
    QMap<QString, double> *requestedData;
};

#endif // INPUTDIALOG_H
