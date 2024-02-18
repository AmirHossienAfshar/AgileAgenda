#include "QSqlQuery"
#include "QSql"
#include <QtSql/QSql>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QFile>
#include <QDir>
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
    ui->tableView->clearSelection();
    ui->tableView_2->clearSelection();
    ui->tableView_3->clearSelection();
    ui->tableView_4->clearSelection();
    ui->tableView_5->clearSelection();

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
    if (!q.exec("SELECT fullDay FROM calender WHERE ToDoListID = 12"))
    {
        qDebug() << "Query failed:" << q.lastError().text();
        return;
    }

    QSqlQuery q2;
    if (!q2.exec("SELECT fullDay FROM calender WHERE ToDoListID = 1"))
    {
        qDebug() << "Query failed:" << q2.lastError().text();
        return;
    }
    //else qDebug () <<"q2 is fine";

    QSqlQuery q3;
    if (!q3.exec("SELECT fullDay FROM calender WHERE ToDoListID = 2"))
    {
        qDebug() << "Query failed:" << q2.lastError().text();
        return;
    }
    //else qDebug () <<"q2 is fine";

    QSqlQuery q4;
    if (!q4.exec("SELECT fullDay FROM calender WHERE ToDoListID = 3"))
    {
        qDebug() << "Query failed:" << q4.lastError().text();
        return;
    }

    QSqlQuery q5;
    if (!q5.exec("SELECT fullDay FROM calender WHERE ToDoListID = 4"))
    {
        qDebug() << "Query failed:" << q5.lastError().text();
        return;
    }


    QSqlQueryModel *m = new QSqlQueryModel;
    QSqlQueryModel *m2 = new QSqlQueryModel;
    QSqlQueryModel *m3 = new QSqlQueryModel;
    QSqlQueryModel *m4 = new QSqlQueryModel;
    QSqlQueryModel *m5 = new QSqlQueryModel;




    m->setQuery(std::move(q));
    ui->tableView->setModel(m);

    m2->setQuery(std::move(q2));
    ui->tableView_2->setModel(m2);

    m3->setQuery(std::move(q3));
    ui->tableView_3->setModel(m3);

    m4->setQuery(std::move(q4));
    ui->tableView_4->setModel(m4);

    m5->setQuery(std::move(q5));
    ui->tableView_5->setModel(m5);

    connect(ui->tableView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &CurrentDay::onSelectionChanged);
    connect(ui->tableView_2->selectionModel(), &QItemSelectionModel::selectionChanged, this, &CurrentDay::onSelectionChanged2);
    connect(ui->tableView_3->selectionModel(), &QItemSelectionModel::selectionChanged, this, &CurrentDay::onSelectionChanged3);
    connect(ui->tableView_4->selectionModel(), &QItemSelectionModel::selectionChanged, this, &CurrentDay::onSelectionChanged4);
    connect(ui->tableView_5->selectionModel(), &QItemSelectionModel::selectionChanged, this, &CurrentDay::onSelectionChanged5);


    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_4->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_5->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


}

void CurrentDay::onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected) {


    ui->tableView_2->clearSelection();
    ui->tableView_3->clearSelection();
    ui->tableView_4->clearSelection();
    ui->tableView_5->clearSelection();
    QModelIndexList selectedRows = selected.indexes();

    if (selectedRows.isEmpty()) {
        // Clear the label if no row is selected
        ui->label->clear();
        ui->tableView->clearSelection();

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
    if (!q.exec("SELECT fullDay FROM calender WHERE DateID = '" + QString::number(row + 8) + "'")) {
        qDebug() << "Query failed:" << q.lastError().text();
        qDebug() << "Row is: " << row;
        return;
    }

    if (q.next())
    {
        ui->label->setText(q.value(0).toString());
        ui->label_2->setText(QString::number(row + 8));
    }
    else
    {
        ui->label->clear(); // Clear the label if no matching row is found
        //ui->label->setText("Choose a valid day.");
    }
}

void CurrentDay::onSelectionChanged2(const QItemSelection &selected, const QItemSelection &deselected) {


    ui->tableView->clearSelection();
    ui->tableView_3->clearSelection();
    ui->tableView_4->clearSelection();
    ui->tableView_5->clearSelection();
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
    if (!q.exec("SELECT fullDay FROM calender WHERE DateID = '" + QString::number(row + 37) + "'")) {
        qDebug() << "Query failed:" << q.lastError().text();
        qDebug() << "Row is: " << row;
        return;
    }

    if (q.next())
    {
        ui->label->setText(q.value(0).toString());
        ui->label_2->setText(QString::number(row + 37));
    }
    else
    {
        ui->label->clear(); // Clear the label if no matching row is found
        //ui->label->setText("Choose a valid day.");
    }
}

void CurrentDay::onSelectionChanged3(const QItemSelection &selected, const QItemSelection &deselected) {


    ui->tableView->clearSelection();
    ui->tableView_2->clearSelection();
    ui->tableView_4->clearSelection();
    ui->tableView_5->clearSelection();
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
    if (!q.exec("SELECT fullDay FROM calender WHERE DateID = '" + QString::number(row + 68) + "'")) {
        qDebug() << "Query failed:" << q.lastError().text();
        qDebug() << "Row is: " << row;
        return;
    }

    if (q.next())
    {
        ui->label->setText(q.value(0).toString());
        ui->label_2->setText(QString::number(row + 68));
    }
    else
    {
        ui->label->clear(); // Clear the label if no matching row is found
        //ui->label->setText("Choose a valid day.");
    }
}


void CurrentDay::onSelectionChanged4(const QItemSelection &selected, const QItemSelection &deselected) {

    ui->tableView->clearSelection();
    ui->tableView_2->clearSelection();
    ui->tableView_3->clearSelection();
    ui->tableView_5->clearSelection();
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
    if (!q.exec("SELECT fullDay FROM calender WHERE DateID = '" + QString::number(row + 99) + "'")) {
        qDebug() << "Query failed:" << q.lastError().text();
        qDebug() << "Row is: " << row;
        return;
    }

    if (q.next())
    {
        ui->label->setText(q.value(0).toString());
        ui->label_2->setText(QString::number(row + 99));
    }
    else
    {
        ui->label->clear(); // Clear the label if no matching row is found
        //ui->label->setText("Choose a valid day.");
    }
}

void CurrentDay::onSelectionChanged5(const QItemSelection &selected, const QItemSelection &deselected) {


    ui->tableView->clearSelection();
    ui->tableView_2->clearSelection();
    ui->tableView_3->clearSelection();
    ui->tableView_4->clearSelection();
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
    if (!q.exec("SELECT fullDay FROM calender WHERE DateID = '" + QString::number(row + 130) + "'")) {
        qDebug() << "Query failed:" << q.lastError().text();
        qDebug() << "Row is: " << row;
        return;
    }

    if (q.next())
    {
        ui->label->setText(q.value(0).toString());
        ui->label_2->setText(QString::number(row + 130));
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
        ui->tableView->clearSelection();
        ui->tableView_2->clearSelection();
        ui->tableView_3->clearSelection();
        ui->tableView_4->clearSelection();
        ui->tableView_5->clearSelection();
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
    QString filePath = QCoreApplication::applicationDirPath() + QDir::separator() + "mydate.txt";
    QFile file(filePath);

    // Open the text file in write mode
    //QFile file("C:\\Users\\user\\Desktop\\AgileAgenda\\AgileAgenda/mydate.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << myDate; // Write myDate to the file
        file.close();
        qDebug() << "file is now added.";
    } else {
        qDebug() << "Failed to open file for writing";
    }
}


