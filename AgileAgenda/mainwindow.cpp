#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDate>
#include <QDir>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include "QSqlQuery"
#include "QSql"
#include <QtSql/QSql>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQueryModel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_2_clicked);


    //QPixmap Logo(":/images/image.png");

    QDate currentDate = QDate::currentDate();
    QString dateString = currentDate.toString("yyyy-MM-dd"); // Adjust the format as needed

    MyDate = dateString;
    ui->labelText->setText(dateString);
    //Show_date(dateString);
    ui->labelText_2->hide();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() // goes to choose day page.
{
    /* old method that could cause memory leak.
    CurrentDay *page2 = new CurrentDay;
    this->hide();
    page2->show();
    */
    emit showCurrentDayPage();
    this->hide();

    QDate currentDate = QDate::currentDate();
    QString dateString = currentDate.toString("yyyy-MM-dd"); // Adjust the format as needed

    MyDate = dateString;
    Show_date(dateString);
    ui->labelText_2->show();

}


void MainWindow::on_pushButton_2_clicked()  // goes directly to plan the current day.
{
    emit showPlannerPage();
    this->hide();

    QDate currentDate = QDate::currentDate();
    QString dateString = currentDate.toString("yyyy-MM-dd");

    MyDate = dateString;
    ui->labelText->setText(dateString);

    saveMyDateToFile(dateString); /// this line is what is going to be diffrent on the choose-day push button

}

void MainWindow::setMyDate(const QString& myVariable)
{
    // Set the value of the variable
    MyDate = myVariable;
}

QString MainWindow::getMyDate() const
{
    // Return the value of the variable
    return MyDate;
}


void MainWindow::saveMyDateToFile(const QString &myDate) {
    // Open the text file in write mode
    QString filePath = QCoreApplication::applicationDirPath() + QDir::separator() + "mydate.txt";
    QFile file(filePath);
    //QFile file("C:\\Users\\user\\Desktop\\AgileAgenda\\AgileAgenda/mydate.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << myDate; // Write myDate to the file
        file.close();
        qDebug() << "file is now added.";
    } else {
        qDebug() << "Failed to open file for writing";
    }
}

QString MainWindow::loadMyDateFromFile() {
    QString myDate;
    // Open the text file in read mode
    QFile file("mydate.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        myDate = in.readAll(); // Read myDate from the file
        file.close();
    } else {
        qDebug() << "Failed to open file for reading";
    }
    return myDate;
}

void MainWindow::Show_date(QString dateString)
{
    QStringList components = dateString.split("-");
    int year = 0, month = 0, day = 0;

    if (components.size() == 3)
    {
        year = components[0].toInt();
        month = components[1].toInt();
        day = components[2].toInt();
    }
    else
    {
        qDebug() << "Invalid date string format!";
    }

    QSqlQuery q2;
    QString queryString = "SELECT fullDay FROM calender WHERE GregorianYear = '" + QString::number(year) + "' AND GregorianMonth = '" + QString::number(month) + "' AND GregorianDay = '" + QString::number(day) + "'";
    //qDebug() << "Query: " << queryString;
    if (!q2.exec(queryString)) {
        qDebug() << "Query failed:" << q2.lastError().text();
        return;
    }

    QString fullDay;
    if (q2.next())
    {
        fullDay = q2.value(0).toString(); // Assuming fullDay is a column in the result
        ui->labelText_2->setText(fullDay); // Set the text of the label to the value retrieved from the query
        qDebug() << "Data retrieved from the query:" << fullDay;
    }
    else
    {
        qDebug() << "No matching date found.";
        return;
    }
}


