#include "QSqlQuery"
#include "QSql"
#include <QtSql/QSql>
#include <QSqlError>

#include "plannerpage.h"
#include "ui_plannerpage.h"

PlannerPage::PlannerPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlannerPage)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &PlannerPage::on_pushButton_clicked);

}

PlannerPage::~PlannerPage()
{
    delete ui;
}

void PlannerPage::on_pushButton_clicked()
{
    emit showMainWindow();
    this->hide();
}


void PlannerPage::on_pushButton_2_clicked()   // the to do list line edith push button.
{

    QSqlDatabase db = QSqlDatabase::database(); // Assuming you've already set up your database connection
    if (!db.isOpen())
    {
        qDebug() << "Database not open!";
        return;
    }
    QSqlQuery query;
    QString text;
    text = ui->textEdit->toPlainText();

    /*
    query.prepare("INSERT INTO Notes (Note) VALUES (?)");
    query.addBindValue(text);
    */
    query.prepare("INSERT INTO Notes (Note) VALUES (:note)");
    query.bindValue(":note", text);
    if (!query.exec())
    {
        qDebug() << "Error inserting note:" << query.lastError().text();
        // Handle the error appropriately
    }
    else
    {
        qDebug() << "Note inserted successfully";
        // Optionally, you can clear the QLineEdit after adding the note
        ui->textEdit->clear();
    }

    qDebug() << "Query:" << query.lastQuery();

}

