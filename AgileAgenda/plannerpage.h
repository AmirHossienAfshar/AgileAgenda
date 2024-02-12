#ifndef PLANNERPAGE_H
#define PLANNERPAGE_H

#include <QMainWindow>

namespace Ui {
class PlannerPage;
}

class PlannerPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlannerPage(QWidget *parent = nullptr);
    ~PlannerPage();

private:
    Ui::PlannerPage *ui;
};

#endif // PLANNERPAGE_H
