#include <QFileDialog>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new BlockScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    setWindowTitle("Block editor - unnamed file");

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
    setWindowTitle("Block editor - unnamed file");
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open schema");
    if (!filename.isEmpty())
        scene->loadFromFile(filename);
    setWindowTitle("Block editor - " + filename);
}

void MainWindow::on_actionSave_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save schema");
    if (!filename.isEmpty())
        scene->saveToFile(filename);
    setWindowTitle("Block editor - " + filename);
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_toggled(bool checked)
{
    scene->setDrawPipe(checked);
}

void MainWindow::on_actionAdd_triggered()
{
    scene->addBlock();
}

void MainWindow::on_actionRemove_triggered()
{
    scene->removeSelected();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About Block editor",
                       "Authors: Václav Doležal, Jiří Vozár");
}
