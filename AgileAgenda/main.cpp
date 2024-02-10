#include "mainwindow.h"
#include "currentday.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    MainWindow mainWindow;
    CurrentDay currentDay;

    QObject::connect(&mainWindow, &MainWindow::showCurrentDayPage, &currentDay, &CurrentDay::show);
    QObject::connect(&currentDay, &CurrentDay::showMainWindow, &mainWindow, &MainWindow::show);

    mainWindow.show();

    return a.exec();
}
