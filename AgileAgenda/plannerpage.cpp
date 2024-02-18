#include "QSqlQuery"
#include "QSql"
#include <QtSql/QSql>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QFile>
#include <QTextStream>
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
    ui->pushButton_5->hide();
    ui->pushButton_7->hide();

    /*QString str = m_mainWindow->getMyDate();
    ui->label->setText(str);*/
    /*if (ui->tableView)
    {
        qDebug () <<"things are fine";
    }
    else
        qDebug()<<"NULLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLl";*/



    /* old method of using a variable between two classes.
    if (m_mainWindow) {
        QString str = m_mainWindow->getMyDate();
        ui->label->setText(str);
    } else {
        qDebug() << "m_mainWindow is null!";
    }
    */

    QString str1 = loadMyDateFromFile();
    //ui->label->setText(str1);
}

PlannerPage::~PlannerPage()
{
    delete ui;
}

void PlannerPage::on_pushButton_clicked() // back to main window
{
    //ui->label->setText("");
    QString str1 = loadMyDateFromFile();
    ui->label->setText(str1);
    emit showMainWindow();
    this->hide();
}


void PlannerPage::on_pushButton_2_clicked()   // insert Note list line edith push button.
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
    QString str1 = loadMyDateFromFile();

    QStringList components = str1.split("-");
    int year, month, day;

    if (components.size() == 3)
    {
        // Extract year, month, and day
        year = components[0].toInt();
        month = components[1].toInt();
        day = components[2].toInt();

        // Print the parsed components

        qDebug() << "Year:" << year;
        qDebug() << "Month:" << month;
        qDebug() << "Day:" << day;

    }
    else
    {
        qDebug() << "Invalid date string format!";
    }


    /*QSqlQuery q;
    if (!q.exec("SELECT DateID FROM calender WHERE GregorianYear ='"+QString::number(year)+"'and GregorianMonth ='"+QString::number(month)+"' and GregorianDay = "+QString::number(day)+""  )) {
        qDebug() << "Query failed:" << q.lastError().text();
        return;
    }*/
    QSqlQuery q;
    QString queryString = "SELECT DateID FROM calender WHERE GregorianYear = '" + QString::number(year) + "' AND GregorianMonth = '" + QString::number(month) + "' AND GregorianDay = '" + QString::number(day) + "'";
    qDebug() << "Query: " << queryString;
    if (!q.exec(queryString)) {
        qDebug() << "Query failed:" << q.lastError().text();
        return;
    }

    QString what_date = "1";

    //QString what_date;
    if (q.next()) {
        what_date = q.value(0).toString();
    } else {
        qDebug() << "No matching date found.";
        return;
    }

    qDebug() << what_date <<"///////////////////////////////////////////////////////////////////////////////////";


    text = ui->textEdit->toPlainText();
    if (text != "")
        query.exec("INSERT INTO Notes (NoteID,DateID,Note) VALUES (NULL,'"+what_date+"','"+text+"')");
        /// important: the problem with null values are handled in the updateNoteID push button.

    ui->textEdit->clear();
    on_pushButton_4_clicked();
    updateNoteIDs(db, what_date.toInt());

    //QString str;
    //str = MainWindow->getMyDate();


}



void PlannerPage::on_pushButton_4_clicked()  // show Notes list
{
    QSqlDatabase db = QSqlDatabase::database(); // Assuming you've already set up your database connection
    if (!db.isOpen())
    {
        qDebug() << "Database not open in the planner page : show push!";
        return;
    }
    else
        qDebug() << "database opend in the planner page : show push";

    QString str1 = loadMyDateFromFile();

    QStringList components = str1.split("-");
    int year, month, day;

    if (components.size() == 3)
    {
        // Extract year, month, and day
        year = components[0].toInt();
        month = components[1].toInt();
        day = components[2].toInt();

        // Print the parsed components

        qDebug() << "Year:" << year;
        qDebug() << "Month:" << month;
        qDebug() << "Day:" << day;

    }
    else
    {
        qDebug() << "Invalid date string format!";
    }

    //day = 17;


    QSqlQuery q2;
    QString queryString = "SELECT DateID FROM calender WHERE GregorianYear = '" + QString::number(year) + "' AND GregorianMonth = '" + QString::number(month) + "' AND GregorianDay = '" + QString::number(day) + "'";
    qDebug() << "Query: " << queryString;
    if (!q2.exec(queryString)) {
        qDebug() << "Query failed:" << q2.lastError().text();
        return;
    }

    QString what_date = "1";

    //QString what_date;
    if (q2.next()) {
        what_date = q2.value(0).toString();
    } else {
        qDebug() << "No matching date found.";
        return;
    }


    QSqlQuery q;
    //q.exec("SELECT * FROM Notes");
    if (!q.exec("SELECT Note FROM Notes WHERE DateID = '" + what_date + "'")) {
        qDebug() << "Query failed:" << q.lastError().text();
        return;
    }


    QSqlQueryModel *m = new QSqlQueryModel;
    m->setQuery(std::move(q));

    ui->tableView->setModel(m);
    //delete m;
    connect(ui->tableView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &PlannerPage::updateDeleteButtonVisibility);

    updateNoteIDs(db, what_date.toInt());
    //qDebug() << "Number of rows in the model: push button:" << m->rowCount();



}


void PlannerPage::on_pushButton_5_clicked()   // delete pushButton for Notes
{
    // Get the selected rows from the table view
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();

    // Start a transaction to ensure atomicity
    QSqlDatabase db = QSqlDatabase::database(); // Assuming you've already set up your database connection
    if (!db.isOpen()) {
        qDebug() << "Database not open!";
        return;
    }

    if (selectedRows.isEmpty()) {
        qDebug() << "No rows selected!";
        return; // No rows selected, nothing to delete
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

    on_pushButton_4_clicked();

    updateNoteIDs(db, 1); // this line is not nessesury since the view push button is clicked on earlier before!!
    /// this line is suspicius!! why is that having deleted 1 instead of date??? yet sounds to work correctly.

    ui->pushButton_5->hide();
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

void PlannerPage::updateToDoIDs(QSqlDatabase& db, int dateID)
{
    QSqlQuery updateQuery(db);

    // Update the NoteID column for rows with the specified DateID

    QString queryStr = QString("UPDATE ToDoList SET ToDoListID = (SELECT COUNT(*) FROM ToDoList AS n WHERE n.DateID = ToDoList.DateID AND n.rowid <= ToDoList.rowid) WHERE DateID = %1").arg(dateID);
    if (!updateQuery.exec(queryStr)) {
        qDebug() << "Error updating ToDoListID column for DateID" << dateID << ":" << updateQuery.lastError().text();
    }
    else
        qDebug() <<"updeted nicly the to do list!";
}

QString PlannerPage::loadMyDateFromFile()
{
    QString myDate;
    // Open the text file in read mode
    //QFile file("mydate.txt"); ///////////////////////////////////////////// as an intersting fact, this works fine but not the other one!
    QFile file("C:\\Users\\user\\Desktop\\AgileAgenda\\AgileAgenda/mydate.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        myDate = in.readAll(); // Read myDate from the file
        file.close();
    } else {
        qDebug() << "Failed to open file for reading";
    }
    return myDate;
}

/*
void PlannerPage::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event); // Call base class implementation

    // Update the text in ui->label whenever the CurrentDay page is shown
    QString str1 = loadMyDateFromFile(); // Assuming loadMyDateFromFile() returns the updated text
    ui->label->setText(str1);
}
*/

void PlannerPage::updateLabel()
{
    QString newData = loadMyDateFromFile(); // Load your data from file or any other source
    ui->label->setText(newData); // Update the label with the new data

    QSqlDatabase db = QSqlDatabase::database(); // Assuming you've already set up your database connection
    if (!db.isOpen())
    {
        qDebug() << "Database not open in the currentday page !";
        return;
    }

    /// this below sets the lable 2. ////////////////////////////////////////////////////////////////////////////////////
    QStringList components = newData.split("-");
    int year = 0, month = 0, day = 0;

    if (components.size() == 3)
    {
        // Extract year, month, and day
        year = components[0].toInt();
        month = components[1].toInt();
        day = components[2].toInt();

        // Print the parsed components
        /*
        qDebug() << "Year:" << year;
        qDebug() << "Month:" << month;
        qDebug() << "Day:" << day;
        */
    }
    else
    {
        qDebug() << "Invalid date string format!";
    }

    QSqlQuery q2;
    QString queryString = "SELECT fullDay FROM calender WHERE GregorianYear = '" + QString::number(year) + "' AND GregorianMonth = '" + QString::number(month) + "' AND GregorianDay = '" + QString::number(day) + "'";
    qDebug() << "Query: " << queryString;
    if (!q2.exec(queryString)) {
        qDebug() << "Query failed:" << q2.lastError().text();
        return;
    }

    QString fullDay;
    if (q2.next())
    {
        fullDay = q2.value(0).toString(); // Assuming fullDay is a column in the result
        ui->label_2->setText(fullDay); // Set the text of the label to the value retrieved from the query
        qDebug() << "Data retrieved from the query:" << fullDay;
    }
    else
    {
        qDebug() << "No matching date found.";
        return;
    }
    /// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    show_notes(fullDay);

}

void PlannerPage::show_notes(QString fullDay) /// this has problem: only clears the notes and not actully show them.
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen())
    {
        qDebug() << "Database not open in the currentday page !";
        return;
    }

    QSqlQuery q;
    if (!q.exec("SELECT Note FROM Notes WHERE DateID = '" + fullDay + "'")) {
        qDebug() << "Query failed:" << q.lastError().text();
        return;
    }

    QSqlQueryModel *m = new QSqlQueryModel;
    m->setQuery(std::move(q));
    //qDebug() << "Number of rows in the model:" << m->rowCount();

    ui->tableView->setModel(m);
    //delete m;

    updateNoteIDs(db, fullDay.toInt()); /// this lin is sus
    ui->tableView->setModel(m);
}




void PlannerPage::on_pushButton_3_clicked() // show To-Do push button // newly added but got some bugs
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen())
    {
        qDebug() << "Database not open in the planner page : show push To-DoList!";
        return;
    }
    else
        qDebug() << "database opend in the planner page : show push";

    QString str1 = loadMyDateFromFile();

    QStringList components = str1.split("-");
    int year =0, month = 0, day = 0;

    if (components.size() == 3)
    {
        // Extract year, month, and day
        year = components[0].toInt();
        month = components[1].toInt();
        day = components[2].toInt();

        // Print the parsed components

        qDebug() << "Year:" << year;
        qDebug() << "Month:" << month;
        qDebug() << "Day:" << day;

    }
    else
    {
        qDebug() << "Invalid date string format!";
    }

    QSqlQuery q2;
    QString queryString = "SELECT DateID FROM calender WHERE GregorianYear = '" + QString::number(year) + "' AND GregorianMonth = '" + QString::number(month) + "' AND GregorianDay = '" + QString::number(day) + "'";
    qDebug() << "Query: " << queryString;
    if (!q2.exec(queryString)) {
        qDebug() << "Query failed:" << q2.lastError().text();
        return;
    }

    QString what_date = "1";

    //QString what_date;
    if (q2.next()) {
        what_date = q2.value(0).toString();
    } else {
        qDebug() << "No matching date found.";
        return;
    }


    QSqlQuery q;
    //q.exec("SELECT * FROM Notes");
    //qDebug() << what_date << "///////////////////////////////////////////////////////////////////////////";
    //if (!q.exec("SELECT * FROM ToDoList ")) {

    if (!q.exec("SELECT Task FROM ToDoList WHERE DateID = '" + what_date + "'")) {
        qDebug() << "Query failed:" << q.lastError().text();
        return;
    }


    QSqlQueryModel *m = new QSqlQueryModel;
    m->setQuery(std::move(q));

    ui->tableView_2->setModel(m);
    //delete m;
    connect(ui->tableView_2->selectionModel(), &QItemSelectionModel::selectionChanged, this, &PlannerPage::updateDeleteButtonVisibility2);

    updateToDoIDs(db, what_date.toInt());
    //qDebug() << "Number of rows in the model: push button:" << m->rowCount();
}


void PlannerPage::on_pushButton_6_clicked() // Insert to To-Do list push button
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen())
    {
        qDebug() << "Database not open in the planner page : insert push button!";
        return;
    }
    else
        qDebug() << "database opend in the planner page : insert push button";

    QSqlQuery query;
    QString text;
    QString str1 = loadMyDateFromFile();

    QStringList components = str1.split("-");
    int year = 0, month = 0, day = 0;

    if (components.size() == 3)
    {
        // Extract year, month, and day
        year = components[0].toInt();
        month = components[1].toInt();
        day = components[2].toInt();

        // Print the parsed components

        qDebug() << "Year:" << year;
        qDebug() << "Month:" << month;
        qDebug() << "Day:" << day;

    }
    else
    {
        qDebug() << "Invalid date string format!";
    }


    QSqlQuery q;
    QString queryString = "SELECT DateID FROM calender WHERE GregorianYear = '" + QString::number(year) + "' AND GregorianMonth = '" + QString::number(month) + "' AND GregorianDay = '" + QString::number(day) + "'";
    qDebug() << "Query: " << queryString;
    if (!q.exec(queryString)) {
        qDebug() << "Query failed:" << q.lastError().text();
        return;
    }

    QString what_date = "1";

    //QString what_date;
    if (q.next()) {
        what_date = q.value(0).toString();
    } else {
        qDebug() << "No matching date found.";
        return;
    }

    text = ui->textEdit->toPlainText();
    if (text != "")
        query.exec("INSERT INTO ToDoList (ToDoListID,Task,DateID) VALUES (NULL,'"+text+"','"+what_date+"')");
    /// important: the problem with null values are handled in the updateNoteID push button.

    ui->textEdit->clear();
    on_pushButton_3_clicked();
    updateToDoIDs(db, what_date.toInt());
}


void PlannerPage::on_pushButton_7_clicked() // delete push button fot To-Do list
{
    // Get the selected rows from the table view
    QModelIndexList selectedRows = ui->tableView_2->selectionModel()->selectedRows();

    // Start a transaction to ensure atomicity
    QSqlDatabase db = QSqlDatabase::database(); // Assuming you've already set up your database connection
    if (!db.isOpen()) {
        qDebug() << "Database not open!";
        return;
    }

    if (selectedRows.isEmpty()) {
        qDebug() << "No rows selected!";
        return; // No rows selected, nothing to delete
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
        query.exec("DELETE FROM ToDoList WHERE ToDoListID = '" + QString::number(row) + "'");


        /*query.prepare("DELETE FROM Notes WHERE RowID = ?");
        query.addBindValue(row + 1); // Adjust for 0-based row numbering
        if (!query.exec()) {
            qDebug() << "Error deleting row from database:" << query.lastError().text();
            db.rollback(); // Rollback the transaction in case of error
            return;
        }*/

        qDebug() << "Row deleted from database";

        // Remove the row from the model
        ui->tableView_2->model()->removeRow(row);
    }

    // Commit the transaction
    if (!db.commit()) {
        qDebug() << "Error committing transaction:" << db.lastError().text();
    }

    on_pushButton_3_clicked();

    updateToDoIDs(db, 1); // this line is not nessesury since the view push button is clicked on earlier before!!
    /// this line is suspicius!! why is that having deleted 1 instead of date??? yet sounds to work correctly.
    ui->pushButton_7->hide();

}

void PlannerPage::updateDeleteButtonVisibility()
{
    // Get the selected rows from the table view
    qDebug() << "Selection changed";

    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();

    // Show the delete button if any rows are selected, hide it otherwise
    ui->pushButton_5->setVisible(!selectedRows.isEmpty());

}

void PlannerPage::updateDeleteButtonVisibility2()
{
    // Get the selected rows from the table view
    qDebug() << "Selection changed";

    QModelIndexList selectedRows = ui->tableView_2->selectionModel()->selectedRows();

    // Show the delete button if any rows are selected, hide it otherwise
    ui->pushButton_7->setVisible(!selectedRows.isEmpty());
}

