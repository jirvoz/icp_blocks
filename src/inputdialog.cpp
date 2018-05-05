/*!
 * \file inputdialog.cpp
 * \brief Source file for InputDialog class
 * \author Jiri Vozar
 * \author Vaclav Dolezal
 */

#include <QFormLayout>

#include "inputdialog.h"

InputDialog::InputDialog(QMap<QString, double> *data, QString slotName, QWidget *parent)
    : QDialog(parent)
{
    requestedData = data;

    QFormLayout *formLayout = new QFormLayout;
    if (data) {
        QMapIterator<QString, double> it(*data);

        // Create spinboxes
        while (it.hasNext()) {
            it.next();
            QDoubleSpinBox *valueSpinBox = new QDoubleSpinBox(this);
            valueSpinBox->setMinimum(-1000000);
            valueSpinBox->setMaximum(1000000);
            valueSpinBox->setValue(it.value());
            spinBoxes.insert(it.key(), valueSpinBox);
            formLayout->addRow(it.key(), valueSpinBox);
        }
    }

    // Create buttons
    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(sendData()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    // Set main layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle("Inset input data for " + slotName);
}

void InputDialog::sendData()
{
    QMapIterator<QString, QDoubleSpinBox *> it(spinBoxes);

    while (it.hasNext()) {
        it.next();
        requestedData->insert(it.key(), it.value()->value());
    }

    accept();
}
