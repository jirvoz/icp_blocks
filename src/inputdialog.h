/*!
 * \file inputdialog.h
 * \brief Header file for InputDialog class
 * \author Jiri Vozar
 * \author Vaclav Dolezal
 */

#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QtWidgets>

#include "datacontainer.h"

class InputDialog : public QDialog
{
public:
    InputDialog(QMap<QString, double> *data, QString slotName, QWidget *parent);

private:
    QMap<QString, double> *requestedData;
    QMap<QString, QDoubleSpinBox *> spinBoxes;
};

#endif // INPUTDIALOG_H
