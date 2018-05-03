#include <QFormLayout>
#include <QtWidgets>

#include "inputdialog.h"

InputDialog::InputDialog(QMap<QString, double> *data, QString slotName, QWidget *parent)
    : QDialog(parent)
{
    QFormLayout *formLayout = new QFormLayout;
    if (data)
    {
        QMapIterator<QString, double> it(*data);

        while (it.hasNext()) {
            it.next();
            formLayout->addRow("fdsa", new QLineEdit());
        }
    }

    formLayout->addRow("", new QDialogButtonBox());
    setLayout(formLayout);
    setWindowTitle("Inset input data for " + slotName);
}
