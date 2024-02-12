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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlannerPage
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PlannerPage)
    {
        if (PlannerPage->objectName().isEmpty())
            PlannerPage->setObjectName("PlannerPage");
        PlannerPage->resize(960, 690);
        PlannerPage->setStyleSheet(QString::fromUtf8("background-color: rgb(142, 148, 124);\n"
""));
        centralwidget = new QWidget(PlannerPage);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setMinimumSize(QSize(451, 91));
        groupBox_3->setMaximumSize(QSize(16777215, 170));
        groupBox_3->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"background-color: rgb(96, 107, 112);\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));

        gridLayout->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setMinimumSize(QSize(450, 631));
        groupBox->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"background-color: rgb(89, 123, 110);\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(70, 150, 181, 91));
        pushButton->setStyleSheet(QString::fromUtf8("border-color: rgb(114, 152, 255);\n"
"background-color: rgb(191, 255, 73);\n"
""));
        pushButton->setCheckable(false);
        pushButton->setAutoDefault(false);
        pushButton->setFlat(false);

        gridLayout->addWidget(groupBox, 0, 1, 2, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setMinimumSize(QSize(450, 521));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 66, 101);\n"
"border-radius: 15px;\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));

        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

        PlannerPage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PlannerPage);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 960, 21));
        PlannerPage->setMenuBar(menubar);
        statusbar = new QStatusBar(PlannerPage);
        statusbar->setObjectName("statusbar");
        PlannerPage->setStatusBar(statusbar);

        retranslateUi(PlannerPage);

        pushButton->setDefault(true);


        QMetaObject::connectSlotsByName(PlannerPage);
    } // setupUi

    void retranslateUi(QMainWindow *PlannerPage)
    {
        PlannerPage->setWindowTitle(QCoreApplication::translate("PlannerPage", "MainWindow", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("PlannerPage", "GroupBox", nullptr));
        groupBox->setTitle(QCoreApplication::translate("PlannerPage", "GroupBox", nullptr));
        pushButton->setText(QCoreApplication::translate("PlannerPage", "go to first page", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("PlannerPage", "GroupBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlannerPage: public Ui_PlannerPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANNERPAGE_H
