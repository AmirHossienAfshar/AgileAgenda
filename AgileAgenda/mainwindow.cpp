#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "currentday.h"
#include <QDate>
#include <QDebug>
#include <QFile>
#include <QTextStream>


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

    //saveMyDateToFile(dateString);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    /* old method that could cause memory leak.
    CurrentDay *page2 = new CurrentDay;
    this->hide();
    page2->show();
    */

    emit showCurrentDayPage();
    this->hide();
}


void MainWindow::on_pushButton_2_clicked()  // goes directly to plan the current day.
{
    emit showPlannerPage();
    this->hide();

    QDate currentDate = QDate::currentDate();
    QString dateString = currentDate.toString("yyyy-MM-dd");

    MyDate = dateString;
    ui->labelText->setText(dateString);

    saveMyDateToFile(dateString);

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
    QFile file("C:\\Users\\user\\Desktop\\AgileAgenda\\AgileAgenda/mydate.txt");
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


