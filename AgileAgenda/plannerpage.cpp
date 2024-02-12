#include "plannerpage.h"
#include "ui_plannerpage.h"

PlannerPage::PlannerPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlannerPage)
{
    ui->setupUi(this);
}

PlannerPage::~PlannerPage()
{
    delete ui;
}
