#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "currentday.h"
#include <QDate>
#include <QDebug>



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


void MainWindow::on_pushButton_2_clicked()
{
    emit showPlannerPage();
    this->hide();

}

void MainWindow::setMyDate(const QString& myVariable) {
    // Set the value of the variable
    MyDate = myVariable;
}

QString MainWindow::getMyDate() const {
    // Return the value of the variable
    return MyDate;
}


