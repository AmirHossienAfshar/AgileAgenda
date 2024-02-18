#include "QSqlQuery"
#include "QSql"
#include <QtSql/QSql>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QFile>
#include <QMessageBox>
#include "currentday.h"
#include "ui_currentday.h"
#include "mainwindow.h"


CurrentDay::CurrentDay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CurrentDay)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &CurrentDay::on_pushButton_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &CurrentDay::on_pushButton_3_clicked);
    // Connect the pageShown signal of the CurrentDay page to a slot that updates the label
    // In MainWindow.cpp (assuming this is where you handle the connections)
    //QObject::connect(&currentDay, &CurrentDay::showPlannerPage, this, &MainWindow::updateLabel);
    ui->label_2->hide();


}

CurrentDay::~CurrentDay()
{
    delete ui;
}

void CurrentDay::on_pushButton_clicked()
{
    emit showMainWindow();
    this->hide();
}


void CurrentDay::on_pushButton_2_clicked() // show push button
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen())
    {
        qDebug() << "Database not open in the currentday page !";
        return;
    }
    else
        qDebug() << "database opend in the currentday page! ";

    QSqlQuery q;
    if (!q.exec("SELECT fullDay FROM calender"))
    {
        qDebug() << "Query failed:" << q.lastError().text();
        return;
    }


    QSqlQueryModel *m = new QSqlQueryModel;
    m->setQuery(std::move(q));

    ui->tableView->setModel(m);
    ui->tableView_2->setModel(m);
    connect(ui->tableView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &CurrentDay::onSelectionChanged);
    connect(ui->tableView_2->selectionModel(), &QItemSelectionModel::selectionChanged, this, &CurrentDay::onSelectionChanged);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);





    /*
    if (ui->tableView->selectionModel())
        qDebug ()<< "yes this isnt null and fine.";
    else {
        qDebug ()<< "here we have a bad null";

    }*/

    /*
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();
    for (auto it = selectedRows.begin(); it != selectedRows.end(); ++it)
    {
        // Get the row index
        int row = it->row();

        row++;
        qDebug() << row;

        ui->label->setText(QString::number(row));
    }
    */

    /*// Commit the transaction
    if (!db.commit()) {
        qDebug() << "Error committing transaction:" << db.lastError().text();
    }*/

}

void CurrentDay::onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected) {


    QModelIndexList selectedRows = selected.indexes();

    if (selectedRows.isEmpty()) {
        // Clear the label if no row is selected
        ui->label->clear();
        return;
    }

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Database not open in the currentday page !";
        return;
    } else {
        qDebug() << "Database opened in the currentday page!";
    }

    QSqlQuery q;

    int row = selectedRows.first().row() + 1;
    if (!q.exec("SELECT fullDay FROM calender WHERE DateID = '" + QString::number(row - 1) + "'")) {
        qDebug() << "Query failed:" << q.lastError().text();
        qDebug() << "Row is: " << row;
        return;
    }

    if (q.next())
    {
        ui->label->setText(q.value(0).toString());
        ui->label_2->setText(QString::number(row - 1));
    }
    else
    {
        ui->label->clear(); // Clear the label if no matching row is found
        //ui->label->setText("Choose a valid day.");
    }
}



void CurrentDay::on_pushButton_3_clicked()  /// chooses the day and goes to planning page.
{

    QString str1 = ui->label_2->text();
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Database not open in the currentday page !";
        return;
    } else {
        qDebug() << "Database opened in the currentday page!";
    }


    QSqlQuery q,q2,q3;
    int year = 0, month = 0 , day = 0;
    if (!q.exec("SELECT GregorianYear FROM calender WHERE DateID = '"+str1+"'"))
    {
        qDebug() << "Query failed:" << q.lastError().text();
        return;
    }
    if (q.next())
    {
        year = q.value(0).toInt();
        //qDebug() << "this is the year in push button" << year;
    }

    if (!q2.exec("SELECT GregorianMonth FROM calender WHERE DateID = '"+str1+"'"))
    {
        qDebug() << "Query failed:" << q2.lastError().text();
        return;
    }
    if (q2.next())
    {
        month = q2.value(0).toInt();
        //qDebug() << "this is the year in push button" << year;
    }

    if (!q3.exec("SELECT GregorianDay FROM calender WHERE DateID = '"+str1+"'"))
    {
        qDebug() << "Query failed:" << q3.lastError().text();
        return;
    }
    if (q3.next())
    {
        day = q3.value(0).toInt();
        //qDebug() << "this is the year in push button" << year;
    }


    //QString strFile = QString::number(year) +"-" + QString::number(month) +"-" +QString::number(day);
    QString strFile = QString("%1-%2-%3")
                          .arg(year)
                          .arg(month, 2, 10, QChar('0'))
                          .arg(day, 2, 10, QChar('0'));

    qDebug() << strFile;


    if (strFile != "0-00-00")
    {
        emit showPlannerPage();
        this->hide();
        saveMyDateToFile(strFile);
    }
    else
    {
        QMessageBox::warning(nullptr, "Error", "Please choose a valid day!", QMessageBox::Ok);
    }

}

void CurrentDay::saveMyDateToFile(const QString &myDate)
{
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


