#include <QFormLayout>

#include "inputdialog.h"

InputDialog::InputDialog(QMap<QString, double> *data, QString slotName, QWidget *parent)
    : QDialog(parent)
{
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
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    // Set main layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle("Inset input data for " + slotName);
}
