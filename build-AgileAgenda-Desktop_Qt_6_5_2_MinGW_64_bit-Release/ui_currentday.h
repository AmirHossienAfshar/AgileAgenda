/********************************************************************************
** Form generated from reading UI file 'currentday.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURRENTDAY_H
#define UI_CURRENTDAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CurrentDay
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CurrentDay)
    {
        if (CurrentDay->objectName().isEmpty())
            CurrentDay->setObjectName("CurrentDay");
        CurrentDay->resize(800, 600);
        centralwidget = new QWidget(CurrentDay);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(290, 190, 221, 131));
        CurrentDay->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CurrentDay);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        CurrentDay->setMenuBar(menubar);
        statusbar = new QStatusBar(CurrentDay);
        statusbar->setObjectName("statusbar");
        CurrentDay->setStatusBar(statusbar);

        retranslateUi(CurrentDay);

        QMetaObject::connectSlotsByName(CurrentDay);
    } // setupUi

    void retranslateUi(QMainWindow *CurrentDay)
    {
        CurrentDay->setWindowTitle(QCoreApplication::translate("CurrentDay", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("CurrentDay", "home page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CurrentDay: public Ui_CurrentDay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURRENTDAY_H
