#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "currentday.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    CurrentDay *page2 = new CurrentDay;
    this->hide();
    page2->show();
}

