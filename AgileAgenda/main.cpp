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



    /*QSqlQuery query;
    query.exec("INSERT INTO calender VALUES('10','?','?','?','?','?')");
    query.prepare("INSERT INTO calender (GregorianYear, GregorianMonth, GregorianDay, PersianYear, PersianMonth, PersianDay) "
                  "VALUES (?, ?, ?, ?, ?, ?)");

    for (int day = 1; day <= 5; ++day) {
        //query.addBindValue(2024); // GregorianYear
        query.addBindValue(2024); // GregorianYear
        query.addBindValue(1);    // GregorianMonth
        query.addBindValue(1);  // GregorianDay
        query.addBindValue(1); // PersianYear (replace with actual value)
        query.addBindValue(1); // PersianMonth (replace with actual value)
        query.addBindValue(1);


        // Execute the INSERT statement
        if (!query.exec()) {
            qDebug() << "Error inserting data:" << query.lastError().text();
            return 1;
        }
        else
           qDebug() << "good";
    }*/

    /*for (int day = 1; day <= 5; ++day)
    {
        query.exec("INSERT INTO calender VALUES('day','?','?','?','?','?')");

    }*/

    //qDebug() << "Data inserted successfully";

    // Close the database connection
    //db.close();



    return a.exec();
}


