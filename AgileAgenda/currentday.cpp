#include "currentday.h"
#include "ui_currentday.h"
#include "mainwindow.h"


CurrentDay::CurrentDay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CurrentDay)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &CurrentDay::on_pushButton_clicked);

}

CurrentDay::~CurrentDay()
{
    delete ui;
}

void CurrentDay::on_pushButton_clicked()
{
    /*
    MainWindow *welcomePage = new MainWindow;
    this->hide();
    welcomePage->show();
    //delete this;  // this part is considered dangerous, try to figure this out.
    */
    emit showMainWindow();
    this->hide();

}

