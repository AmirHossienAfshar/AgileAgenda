#include "mainwindow.h"
#include "currentday.h"
#include "plannerpage.h"
#include <QApplication>
#include <QDir>
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
    QObject::connect(&currentDay, &CurrentDay::showPlannerPage, &plannerPage, &PlannerPage::show);
    QObject::connect(&plannerPage, &PlannerPage::showMainWindow, &mainWindow, &MainWindow::show);

    // connections to update lable;
    QObject::connect(&currentDay, &CurrentDay::showPlannerPage, &plannerPage, &PlannerPage::updateLabel);
    QObject::connect(&mainWindow, &MainWindow::showPlannerPage, &plannerPage, &PlannerPage::updateLabel);




    mainWindow.show();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName("Callender.db"); //

    //db.setDatabaseName("C:\\Users\\user\\Desktop\\AgileAgenda\\AgileAgenda\\Callender.db");

    // Set the database file path
    QString databaseFilePath = QCoreApplication::applicationDirPath() + QDir::separator() + "Callender.db";
    db.setDatabaseName(databaseFilePath);

    if (!db.open()) {

        qDebug() << "Error: Failed to open database:" << db.lastError().text();
        return 1;
    }
    else
        qDebug() << "the data base is opend in the main";


    return a.exec();
}


