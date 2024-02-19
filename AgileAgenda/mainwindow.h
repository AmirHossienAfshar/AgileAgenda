#include "currentday.h"
//#include "plannerpage.h"

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString getMyDate() const; // Change return type to QString
    void setMyDate(const QString& myVariable); // Change parameter type to QString



signals:
    void showCurrentDayPage();
    void showPlannerPage();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void saveMyDateToFile(const QString &myDate);
    QString loadMyDateFromFile();

    void Show_date(QString);


private:
    Ui::MainWindow *ui;
    QString MyDate;
};
#endif // MAINWINDOW_H
