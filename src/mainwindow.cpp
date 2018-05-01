#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new BlockScene();
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    //scene->clearScene();
}

void MainWindow::on_actionOpen_triggered()
{
    //scene->loadFromFile("");
}

void MainWindow::on_actionSave_triggered()
{
    //scene->saveToFile("");
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}
