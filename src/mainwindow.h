#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "blockscene.h"
#include "blockslot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void updateLabel(QString text);
    bool getSlotInput(QMap<QString, double> *data, QString slotName);
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionExit_triggered();
    void on_pushButton_toggled(bool checked);
    void on_actionAdd_triggered();
    void on_actionRemove_triggered();
    void on_actionAbout_triggered();
    void on_actionCompute_all_triggered();

private:
    Ui::MainWindow *ui;

    BlockScene *scene;
};

#endif // MAINWINDOW_H
