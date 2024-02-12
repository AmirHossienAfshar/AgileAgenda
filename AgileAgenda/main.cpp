#include "mainwindow.h"
#include "currentday.h"
#include "plannerpage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainWindow;
    CurrentDay currentDay;
    PlannerPage plannerPage;

    QObject::connect(&mainWindow, &MainWindow::showCurrentDayPage, &currentDay, &CurrentDay::show);
    QObject::connect(&mainWindow, &MainWindow::showPlannerPage, &plannerPage, &PlannerPage::show);
    QObject::connect(&currentDay, &CurrentDay::showMainWindow, &mainWindow, &MainWindow::show);

    // Connect showPlannerPage() signal from MainWindow to a slot in MainWindow
    //QObject::connect(&mainWindow, &MainWindow::showPlannerPage, &mainWindow, &MainWindow::showPlannerPage);


    mainWindow.show();

    return a.exec();
}
