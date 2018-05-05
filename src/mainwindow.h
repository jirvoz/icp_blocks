/*!
 * \file mainwindow.h
 * \brief Header file for MainWindow class
 * \author Jiri Vozar
 * \author Vaclav Dolezal
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "blockscene.h"
#include "blockslot.h"

namespace Ui {
class MainWindow;
}

/*!
 * \brief MainWindow class representing the GUI of the application
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief MainWindow constructor
     * \param parent parent widget
     */
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    /*!
     * \brief Display text from backend in GUI
     * \param text text to display
     */
    void updateLabel(QString text);
    /*!
     * \brief Launch dialog for entering input values for unconnected slots
     * \param data pointer to data structure to fill
     * \param slotName name of slot for displaying in dialog title
     * \return success of confirming the dialog
     */
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
    void on_actionStep_triggered();

private:
    Ui::MainWindow *ui;

    BlockScene *scene;   //!< Backend scene object, which is drawn on QGraphicsView
};

#endif // MAINWINDOW_H
