#include "QSqlQuery"
#include "QSql"
#include <QtSql/QSql>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQueryModel>

#include "plannerpage.h"
#include "ui_plannerpage.h"
//#include "mainwindow.h"

PlannerPage::PlannerPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlannerPage)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &PlannerPage::on_pushButton_clicked);

    connect(ui->pushButton_5, &QPushButton::clicked, this, &PlannerPage::on_pushButton_5_clicked);

    /*QString str = m_mainWindow->getMyDate();
    ui->label->setText(str);*/

    if (m_mainWindow) {
        QString str = m_mainWindow->getMyDate();
        ui->label->setText(str);
    } else {
        qDebug() << "m_mainWindow is null!";
    }



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

    QString what_date = "1";
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
        query.exec("INSERT INTO Notes (NoteID,DateID,Note) VALUES (NULL,'"+what_date+"','"+text+"')");


    ui->textEdit->clear();
    on_pushButton_4_clicked();
    updateNoteIDs(db, 1);

    QString str;
    //str = MainWindow->getMyDate();


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
    if (!q.exec("SELECT Note FROM Notes WHERE DateID = 1")) { ////////////////////////////////////////////////////////////////////////////
        qDebug() << "Query failed:" << q.lastError().text();
        return;
    }

    /*
    // Print the results of the query
    qDebug() << "Query results:";
    while (q.next()) {
        // Assuming Notes table has two columns: 'id' and 'content'
        qDebug() << "ID:" << q.value(0).toInt() << ", Content:" << q.value(1).toString();
    }
    */

    QSqlQueryModel *m = new QSqlQueryModel;
    m->setQuery(std::move(q));

    ui->tableView->setModel(m);
    //delete m;

    updateNoteIDs(db, 1);


}


void PlannerPage::on_pushButton_5_clicked()   // delete pushButton
{
    // Get the selected rows from the table view
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();

    // Start a transaction to ensure atomicity
    QSqlDatabase db = QSqlDatabase::database(); // Assuming you've already set up your database connection
    if (!db.isOpen()) {
        qDebug() << "Database not open!";
        return;
    }
    db.transaction();


    // Iterate through the selected rows
    for (auto it = selectedRows.begin(); it != selectedRows.end(); ++it)
    {
        // Get the row index
        int row = it->row();


        // Delete the corresponding data from the database
        QSqlQuery query;
        row++;
        qDebug() << row;
        query.exec("DELETE FROM Notes WHERE NoteID = '" + QString::number(row) + "'");


        /*query.prepare("DELETE FROM Notes WHERE RowID = ?");
        query.addBindValue(row + 1); // Adjust for 0-based row numbering
        if (!query.exec()) {
            qDebug() << "Error deleting row from database:" << query.lastError().text();
            db.rollback(); // Rollback the transaction in case of error
            return;
        }*/

        qDebug() << "Row deleted from database";

        // Remove the row from the model
        ui->tableView->model()->removeRow(row);
    }

    // Commit the transaction
    if (!db.commit()) {
        qDebug() << "Error committing transaction:" << db.lastError().text();
    }

    on_pushButton_4_clicked();  // Update the view (optional)


    /*QSqlQuery query;
    auto it = selectedRows.begin();
    int row = it->row();
    row++;
    qDebug() << row;
    query.exec("DELETE FROM Notes WHERE RowID = '" + QString::number(row) + "'");
    */

    updateNoteIDs(db, 1); // this line is not nessesury since the view push button is clicked on earlier before!!

}

void PlannerPage::updateNoteIDs(QSqlDatabase& db, int dateID)
{
    QSqlQuery updateQuery(db);

    // Update the NoteID column for rows with the specified DateID

    QString queryStr = QString("UPDATE Notes SET NoteID = (SELECT COUNT(*) FROM Notes AS n WHERE n.DateID = Notes.DateID AND n.rowid <= Notes.rowid) WHERE DateID = %1").arg(dateID);
    if (!updateQuery.exec(queryStr)) {
        qDebug() << "Error updating NoteID column for DateID" << dateID << ":" << updateQuery.lastError().text();
    }
    else
        qDebug() <<"updeted nicly!";
}



