/********************************************************************************
** Form generated from reading UI file 'plannerpage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLANNERPAGE_H
#define UI_PLANNERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlannerPage
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PlannerPage)
    {
        if (PlannerPage->objectName().isEmpty())
            PlannerPage->setObjectName("PlannerPage");
        PlannerPage->resize(800, 600);
        centralwidget = new QWidget(PlannerPage);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 170, 311, 121));
        PlannerPage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PlannerPage);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        PlannerPage->setMenuBar(menubar);
        statusbar = new QStatusBar(PlannerPage);
        statusbar->setObjectName("statusbar");
        PlannerPage->setStatusBar(statusbar);

        retranslateUi(PlannerPage);

        QMetaObject::connectSlotsByName(PlannerPage);
    } // setupUi

    void retranslateUi(QMainWindow *PlannerPage)
    {
        PlannerPage->setWindowTitle(QCoreApplication::translate("PlannerPage", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("PlannerPage", "wellcome to the page?!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlannerPage: public Ui_PlannerPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANNERPAGE_H
