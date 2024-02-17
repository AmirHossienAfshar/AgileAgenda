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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CurrentDay
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QTableView *tableView;
    QLabel *label;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CurrentDay)
    {
        if (CurrentDay->objectName().isEmpty())
            CurrentDay->setObjectName("CurrentDay");
        CurrentDay->resize(960, 690);
        CurrentDay->setStyleSheet(QString::fromUtf8("background-color: rgb(142, 148, 124);\n"
"border-radius: 10px;\n"
""));
        centralwidget = new QWidget(CurrentDay);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(700, 450, 171, 111));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 66, 101);\n"
"border-radius: 15px;\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 20, 601, 601));
        groupBox->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"background-color: rgb(96, 107, 112);\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));
        tableView = new QTableView(groupBox);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(40, 30, 501, 441));
        tableView->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 66, 101);\n"
"border-radius: 15px;\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 500, 311, 51));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 66, 101);\n"
"border-radius: 15px;\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(370, 500, 161, 51));
        CurrentDay->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CurrentDay);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 960, 21));
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
        groupBox->setTitle(QCoreApplication::translate("CurrentDay", "GroupBox", nullptr));
        label->setText(QCoreApplication::translate("CurrentDay", "TextLabel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CurrentDay", "show", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CurrentDay: public Ui_CurrentDay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURRENTDAY_H
