/*!
 * \file mainwindow.cpp
 * \brief Source file for MainWindow class
 * \author Jiri Vozar
 * \author Vaclav Dolezal
 */

#include <QFileDialog>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inputdialog.h"

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
    ui->dataLabel->setText(text);
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

void MainWindow::on_actionCompute_all_triggered()
{
    scene->compute();
}

void MainWindow::on_actionStep_triggered()
{
    if (!scene->isComputing())
        scene->computeInit();
    scene->computeStep();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About Block editor",
                       "Authors: Václav Doležal, Jiří Vozár");
}

void MainWindow::on_removePushButton_clicked()
{
    scene->removeSelected();
}

void MainWindow::on_abs3PushButton_clicked()
{
    scene->createBlock<BlockItem_abs3>();
}

void MainWindow::on_vec3PushButton_clicked()
{
    scene->createBlock<BlockItem_vec3>();
}

void MainWindow::on_num3PushButton_clicked()
{
    scene->createBlock<BlockItem_num3>();
}

void MainWindow::on_abs2PushButton_clicked()
{
    scene->createBlock<BlockItem_abs2>();
}

void MainWindow::on_vec2PushButton_clicked()
{
    scene->createBlock<BlockItem_vec2>();
}

void MainWindow::on_num2PushButton_clicked()
{
    scene->createBlock<BlockItem_num2>();
}
