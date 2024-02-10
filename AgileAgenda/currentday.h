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

private slots:
    void on_pushButton_clicked();

private:
    Ui::CurrentDay *ui;
};

#endif // CURRENTDAY_H
