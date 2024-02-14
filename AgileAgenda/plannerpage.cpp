#include "QSqlQuery"
#include "QSql"
#include <QtSql/QSql>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQueryModel>

#include "plannerpage.h"
#include "ui_plannerpage.h"

PlannerPage::PlannerPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlannerPage)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &PlannerPage::on_pushButton_clicked);

    // no need to reOpen the sql, only using the old connection is fine!
    //QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE");
    //db2.setDatabaseName("../Calendar.db");


    /* not possible to load the old connection in the constuctor, duo to the timing, the old conecction is not set yet here!
    QSqlDatabase db = QSqlDatabase::database();

    if (!db.isOpen())
    {
        qDebug() << "Database not open in the planner page!"<<db.lastError().text();
        return;
    }
    else
        qDebug() << "database opend in the planner page";
    */

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


void PlannerPage::on_pushButton_2_clicked()   // insert To-do list line edith push button.
{

    QSqlDatabase db = QSqlDatabase::database(); // Assuming you've already set up your database connection
    if (!db.isOpen())
    {
        qDebug() << "Database not open in the planner page : insert push button!";
        return;
    }
    else
        qDebug() << "database opend in the planner page : insert push button";

    QSqlQuery query;
    QString text;

    text = ui->textEdit->toPlainText();
    if (text != "")
        query.exec("INSERT INTO Notes (NoteID,DateID,Note) VALUES (NULL,NULL,'"+text+"')");


    ui->textEdit->clear();
    on_pushButton_4_clicked();

}



void PlannerPage::on_pushButton_4_clicked()  // show To-do list
{
    QSqlDatabase db = QSqlDatabase::database(); // Assuming you've already set up your database connection
    if (!db.isOpen())
    {
        qDebug() << "Database not open in the planner page : show push!";
        return;
    }
    else
        qDebug() << "database opend in the planner page : show push";

    QSqlQuery q;
    //q.exec("SELECT * FROM Notes");
    if (!q.exec("SELECT Note FROM Notes")) {
        qDebug() << "Query failed:" << q.lastError().text();
        return;
    }

    // Print the results of the query
    qDebug() << "Query results:";
    while (q.next()) {
        // Assuming Notes table has two columns: 'id' and 'content'
        qDebug() << "ID:" << q.value(0).toInt() << ", Content:" << q.value(1).toString();
    }

    QSqlQueryModel *m = new QSqlQueryModel;
    m->setQuery(std::move(q));

    ui->tableView->setModel(m);


}


void PlannerPage::on_pushButton_5_clicked()
{


}

/*
    query.prepare("INSERT INTO Notes (Note) VALUES (?)");
    query.addBindValue(text);
    */

/*
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
    */


