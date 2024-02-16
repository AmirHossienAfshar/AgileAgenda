#include "mainwindow.h"
#include "currentday.h"
#include "plannerpage.h"
#include <QApplication>
#include <QCoreApplication>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlError>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainWindow;
    CurrentDay currentDay;
    PlannerPage plannerPage;

    QObject::connect(&mainWindow, &MainWindow::showCurrentDayPage, &currentDay, &CurrentDay::show);
    QObject::connect(&mainWindow, &MainWindow::showPlannerPage, &plannerPage, &PlannerPage::show);
    QObject::connect(&currentDay, &CurrentDay::showMainWindow, &mainWindow, &MainWindow::show);
    QObject::connect(&plannerPage, &PlannerPage::showMainWindow, &mainWindow, &MainWindow::show);


    mainWindow.show();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName("Callender.db"); //
    db.setDatabaseName("C:\\Users\\user\\Desktop\\AgileAgenda\\AgileAgenda\\Callender.db");
    if (!db.open()) {

        qDebug() << "Error: Failed to open database:" << db.lastError().text();
        return 1;
    }
    else
        qDebug() << "the data base is opend in the main";


    return a.exec();
}


