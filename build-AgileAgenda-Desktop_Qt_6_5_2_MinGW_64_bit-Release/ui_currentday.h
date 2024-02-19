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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CurrentDay
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QTableView *tableView;
    QTableView *tableView_2;
    QTableView *tableView_3;
    QTableView *tableView_4;
    QTableView *tableView_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CurrentDay)
    {
        if (CurrentDay->objectName().isEmpty())
            CurrentDay->setObjectName("CurrentDay");
        CurrentDay->resize(1083, 712);
        CurrentDay->setStyleSheet(QString::fromUtf8("background-color: rgb(142, 148, 124);\n"
"border-radius: 10px;\n"
""));
        centralwidget = new QWidget(CurrentDay);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(101, 51));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 66, 101);\n"
"border-radius: 15px;\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setMinimumSize(QSize(1061, 621));
        groupBox->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"background-color: rgb(96, 107, 112);\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setMinimumSize(QSize(1011, 501));
        groupBox_2->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"background-color: rgb(89, 123, 110);\n"
"font: 900 16pt \"Maven Pro\";\n"
"color:  rgb(50, 66, 101);\n"
""));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName("gridLayout_3");
        tableView = new QTableView(groupBox_2);
        tableView->setObjectName("tableView");
        tableView->setMinimumSize(QSize(191, 441));
        tableView->setMaximumSize(QSize(265, 16777215));
        tableView->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 66, 101);\n"
"border-radius: 15px;\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));
        tableView->setFrameShape(QFrame::StyledPanel);

        gridLayout_3->addWidget(tableView, 0, 0, 1, 1);

        tableView_2 = new QTableView(groupBox_2);
        tableView_2->setObjectName("tableView_2");
        tableView_2->setMinimumSize(QSize(191, 441));
        tableView_2->setMaximumSize(QSize(265, 16777215));
        tableView_2->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 66, 101);\n"
"border-radius: 15px;\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));

        gridLayout_3->addWidget(tableView_2, 0, 1, 1, 1);

        tableView_3 = new QTableView(groupBox_2);
        tableView_3->setObjectName("tableView_3");
        tableView_3->setMinimumSize(QSize(191, 441));
        tableView_3->setMaximumSize(QSize(265, 16777215));
        tableView_3->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 66, 101);\n"
"border-radius: 15px;\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));

        gridLayout_3->addWidget(tableView_3, 0, 2, 1, 1);

        tableView_4 = new QTableView(groupBox_2);
        tableView_4->setObjectName("tableView_4");
        tableView_4->setMinimumSize(QSize(191, 441));
        tableView_4->setMaximumSize(QSize(265, 16777215));
        tableView_4->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 66, 101);\n"
"border-radius: 15px;\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));

        gridLayout_3->addWidget(tableView_4, 0, 3, 1, 1);

        tableView_5 = new QTableView(groupBox_2);
        tableView_5->setObjectName("tableView_5");
        tableView_5->setMinimumSize(QSize(191, 441));
        tableView_5->setMaximumSize(QSize(265, 16777215));
        tableView_5->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 66, 101);\n"
"border-radius: 15px;\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));

        gridLayout_3->addWidget(tableView_5, 0, 4, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 1, 0, 1, 4);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(191, 71));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 66, 101);\n"
"border-radius: 15px;\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));

        gridLayout_2->addWidget(pushButton_3, 2, 2, 1, 1);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(111, 71));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("border-color: rgb(114, 152, 255);\n"
"font: 900 11pt \"Maven Pro\";\n"
"background-color: rgb(191, 255, 73);\n"
""));

        gridLayout_2->addWidget(pushButton, 2, 3, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setMinimumSize(QSize(431, 71));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 66, 101);\n"
"border-radius: 15px;\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 2, 1, 1, 1);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(231, 71));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"background-color: rgb(89, 123, 110);\n"
"font: 900 16pt \"Maven Pro\";\n"
"color:  rgb(50, 66, 101);\n"
""));

        gridLayout_2->addWidget(pushButton_2, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        CurrentDay->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CurrentDay);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1083, 21));
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
        label_2->setText(QCoreApplication::translate("CurrentDay", "hidden ", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CurrentDay", "calendar", nullptr));
        groupBox_2->setTitle(QString());
        pushButton_3->setText(QCoreApplication::translate("CurrentDay", "select Day", nullptr));
        pushButton->setText(QCoreApplication::translate("CurrentDay", "home page", nullptr));
        label->setText(QCoreApplication::translate("CurrentDay", "Choose a valid day", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CurrentDay", "show", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CurrentDay: public Ui_CurrentDay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURRENTDAY_H
