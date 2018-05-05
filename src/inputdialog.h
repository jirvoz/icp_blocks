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

/*!
 * \brief InputDialog class for entering input values for computation
 * Dialog reads all records in dictionary of input values and creates
 * form with input for every value. When form is successfully submited,
 * values are written to the dictionary.
 */
class InputDialog : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief InputDialog constructor
     * \param data pointer to data dictionary which will be filled with values
     * \param slotName slot name for window title
     * \param parent parent widget/window
     */
    InputDialog(QMap<QString, double> *data, QString slotName, QWidget *parent);

public slots:
    /*!
     * \brief Copy user data from input form to target data structure and confirm dialog
     */
    void sendData();

private:
    QMap<QString, double> *requestedData;       //!< Local pointer to dictionary to fill
    QMap<QString, QDoubleSpinBox *> spinBoxes;  //!< Dictionary of input widgets with desired values
};

#endif // INPUTDIALOG_H
