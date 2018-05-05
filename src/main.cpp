/*!
 * \file main.cpp
 * \brief Source file for launching the app
 * \author Jiri Vozar
 * \author Vaclav Dolezal
 */

#include "mainwindow.h"
#include <QApplication>

/*!
 * \brief Main function for starting the app
 * \param argc argument count
 * \param argv array of arguments
 * \return exit code
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
