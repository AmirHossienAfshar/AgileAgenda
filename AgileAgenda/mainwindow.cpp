#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "currentday.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);

    QPixmap Logo(":/images/image.png");
    //ui->label->setFixedSize(Logo.size());

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

