
#ifndef PLANNERPAGE_H
#define PLANNERPAGE_H

#include "qsqldatabase.h"
#include "mainwindow.h"

#include <QMainWindow>

namespace Ui {
class PlannerPage;
}

class PlannerPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlannerPage(QWidget *parent = nullptr);
    void updateNoteIDs(QSqlDatabase& db, int dateID); ////////////////////////////////////////////////////////////
    void updateToDoIDs(QSqlDatabase& db, int dateID);
    void updateLabel();

    ~PlannerPage();

signals:
    void showMainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    QString loadMyDateFromFile();

    void show_notes(QString);


//protected:


    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::PlannerPage *ui;
    const MainWindow *m_mainWindow; // Const pointer to MainWindow instance ////////////////////////////////////////this is added

};

#endif // PLANNERPAGE_H
