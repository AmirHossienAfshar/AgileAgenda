#include <QModelIndexList>
#include <QItemSelection>
#include <QModelIndex>


#ifndef CURRENTDAY_H
#define CURRENTDAY_H

#include <QMainWindow>

namespace Ui {
class CurrentDay;
}

class CurrentDay : public QMainWindow
{
    Q_OBJECT

public:
    explicit CurrentDay(QWidget *parent = nullptr);
    ~CurrentDay();

signals:
    void showMainWindow();
    void showPlannerPage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

    void on_pushButton_3_clicked();

private:
    Ui::CurrentDay *ui;
};

#endif // CURRENTDAY_H
