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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlannerPage
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox;
    QGroupBox *groupBox_5;
    QTextEdit *textEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QTableView *tableView;
    QGroupBox *groupBox_4;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_4;
    QTextEdit *textEdit_2;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PlannerPage)
    {
        if (PlannerPage->objectName().isEmpty())
            PlannerPage->setObjectName("PlannerPage");
        PlannerPage->resize(960, 758);
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
        groupBox->setMinimumSize(QSize(450, 521));
        groupBox->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"background-color: rgb(89, 123, 110);\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));
        groupBox_5 = new QGroupBox(groupBox);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(10, 350, 441, 151));
        groupBox_5->setMinimumSize(QSize(441, 151));
        groupBox_5->setMaximumSize(QSize(900, 151));
        groupBox_5->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 107, 112);\n"
""));
        textEdit = new QTextEdit(groupBox_5);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(9, 20, 331, 111));
        textEdit->setMinimumSize(QSize(300, 111));
        textEdit->setMaximumSize(QSize(16777215, 111));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 66, 101);\n"
"border-radius: 15px;\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));
        pushButton_2 = new QPushButton(groupBox_5);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(350, 80, 81, 55));
        pushButton_2->setMinimumSize(QSize(81, 55));
        pushButton_2->setMaximumSize(QSize(81, 111));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 66, 101);\n"
"border-radius: 15px;\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));
        pushButton_4 = new QPushButton(groupBox_5);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(350, 20, 81, 55));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 66, 101);\n"
"border-radius: 15px;\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));
        tableView = new QTableView(groupBox);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 40, 441, 301));
        tableView->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 107, 112);\n"
"color: rgb(8, 8, 8);\n"
""));

        gridLayout->addWidget(groupBox, 0, 1, 2, 1);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setMinimumSize(QSize(468, 104));
        groupBox_4->setMaximumSize(QSize(16777215, 170));
        groupBox_4->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"background-color: rgb(96, 107, 112);\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));
        pushButton = new QPushButton(groupBox_4);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 40, 181, 91));
        pushButton->setStyleSheet(QString::fromUtf8("border-color: rgb(114, 152, 255);\n"
"background-color: rgb(191, 255, 73);\n"
""));
        pushButton->setCheckable(false);
        pushButton->setAutoDefault(false);
        pushButton->setFlat(false);

        gridLayout->addWidget(groupBox_4, 2, 1, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setMinimumSize(QSize(450, 521));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 66, 101);\n"
"border-radius: 15px;\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));
        groupBox_6 = new QGroupBox(groupBox_2);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(10, 330, 441, 151));
        groupBox_6->setMinimumSize(QSize(441, 151));
        groupBox_6->setMaximumSize(QSize(900, 151));
        groupBox_6->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 107, 112);\n"
""));
        gridLayout_4 = new QGridLayout(groupBox_6);
        gridLayout_4->setObjectName("gridLayout_4");
        textEdit_2 = new QTextEdit(groupBox_6);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setMinimumSize(QSize(331, 111));
        textEdit_2->setMaximumSize(QSize(16777215, 111));
        textEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(89, 123, 110);\n"
"border-radius: 15px;\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));

        gridLayout_4->addWidget(textEdit_2, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(groupBox_6);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(81, 111));
        pushButton_3->setMaximumSize(QSize(81, 111));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(89, 123, 110);\n"
"border-radius: 15px;\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));

        gridLayout_4->addWidget(pushButton_3, 0, 1, 1, 1);


        gridLayout->addWidget(groupBox_2, 1, 0, 2, 1);

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
        groupBox_3->setTitle(QCoreApplication::translate("PlannerPage", "Callender", nullptr));
        groupBox->setTitle(QCoreApplication::translate("PlannerPage", "To-Do list", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("PlannerPage", "GroupBox", nullptr));
        pushButton_2->setText(QCoreApplication::translate("PlannerPage", "submit", nullptr));
        pushButton_4->setText(QCoreApplication::translate("PlannerPage", "show", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("PlannerPage", "Menu", nullptr));
        pushButton->setText(QCoreApplication::translate("PlannerPage", "go to first page", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("PlannerPage", "Notes", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("PlannerPage", "GroupBox", nullptr));
        pushButton_3->setText(QCoreApplication::translate("PlannerPage", "submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlannerPage: public Ui_PlannerPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANNERPAGE_H
