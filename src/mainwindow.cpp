#include <QFileDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new BlockScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    connect(scene, SIGNAL(updateLabel(QString)), this, SLOT(updateLabel(QString)));
    statusBar()->showMessage("Hello there, general Kenobi.");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateLabel(QString text)
{
    ui->label->setText(text);
}

void MainWindow::on_actionNew_triggered()
{
    scene->clearScene();
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open schema");
    if (!filename.isEmpty())
        scene->loadFromFile(filename);
}

void MainWindow::on_actionSave_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save schema");
    if (!filename.isEmpty())
        scene->saveToFile(filename);
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionPipe_toggled(bool arg1)
{
    scene->setDrawPipe(arg1);
}
