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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QTableView *tableView;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QTableView *tableView_2;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QTextEdit *textEdit;
    QPushButton *pushButton_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QPushButton *pushButton_6;
    QPushButton *pushButton_2;
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
        groupBox_3->setMinimumSize(QSize(451, 170));
        groupBox_3->setMaximumSize(QSize(16777215, 170));
        groupBox_3->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"background-color: rgb(96, 107, 112);\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName("gridLayout_3");
        label = new QLabel(groupBox_3);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"background-color: rgb(89, 123, 110);\n"
"font: 900 16pt \"Maven Pro\";\n"
"color:  rgb(50, 66, 101);\n"
""));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label, 1, 1, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"background-color: rgb(89, 123, 110);\n"
"font: 900 16pt \"Maven Pro\";\n"
"color:  rgb(50, 66, 101);\n"
""));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_2, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"background-color: rgb(89, 123, 110);\n"
"font: 900 16pt \"Maven Pro\";\n"
"color:  rgb(50, 66, 101);\n"
""));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_4, 2, 0, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"background-color: rgb(89, 123, 110);\n"
"font: 900 16pt \"Maven Pro\";\n"
"color:  rgb(50, 66, 101);\n"
""));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_3, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setMinimumSize(QSize(450, 521));
        groupBox->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"background-color: rgb(89, 123, 110);\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName("gridLayout_4");
        tableView = new QTableView(groupBox);
        tableView->setObjectName("tableView");
        tableView->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 107, 112);\n"
"color: rgb(8, 8, 8);\n"
""));

        gridLayout_4->addWidget(tableView, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(verticalSpacer_2, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 1, 2, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setMinimumSize(QSize(450, 100));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 66, 101);\n"
"border-radius: 15px;\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setObjectName("gridLayout_5");
        tableView_2 = new QTableView(groupBox_2);
        tableView_2->setObjectName("tableView_2");
        tableView_2->setStyleSheet(QString::fromUtf8("background-color: rgb(96, 107, 112);\n"
"color: rgb(8, 8, 8);\n"
""));

        gridLayout_5->addWidget(tableView_2, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_5->addItem(verticalSpacer_3, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setMinimumSize(QSize(931, 121));
        groupBox_4->setMaximumSize(QSize(16777215, 121));
        groupBox_4->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"background-color: rgb(96, 107, 112);\n"
"font: 900 10pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setObjectName("gridLayout_2");
        textEdit = new QTextEdit(groupBox_4);
        textEdit->setObjectName("textEdit");
        textEdit->setMinimumSize(QSize(300, 50));
        textEdit->setMaximumSize(QSize(16777215, 91));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 66, 101);\n"
"border-radius: 15px;\n"
"font: 900 16pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));

        gridLayout_2->addWidget(textEdit, 0, 0, 2, 1);

        pushButton_3 = new QPushButton(groupBox_4);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(91, 41));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 66, 101);\n"
"border-radius: 15px;\n"
"font: 900 10pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));

        gridLayout_2->addWidget(pushButton_3, 0, 1, 1, 1);

        pushButton_7 = new QPushButton(groupBox_4);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setMinimumSize(QSize(51, 91));
        pushButton_7->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 66, 101);\n"
"border-radius: 15px;\n"
"font: 900 11pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));

        gridLayout_2->addWidget(pushButton_7, 0, 2, 2, 1);

        pushButton_4 = new QPushButton(groupBox_4);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMinimumSize(QSize(91, 41));
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 66, 101);\n"
"border-radius: 15px;\n"
"font: 900 10pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));

        gridLayout_2->addWidget(pushButton_4, 0, 3, 1, 1);

        pushButton_5 = new QPushButton(groupBox_4);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setMinimumSize(QSize(51, 91));
        pushButton_5->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 66, 101);\n"
"border-radius: 15px;\n"
"font: 900 11pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));

        gridLayout_2->addWidget(pushButton_5, 0, 4, 2, 1);

        pushButton = new QPushButton(groupBox_4);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(81, 91));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("border-color: rgb(114, 152, 255);\n"
"font: 900 11pt \"Maven Pro\";\n"
"background-color: rgb(191, 255, 73);\n"
""));
        pushButton->setCheckable(false);
        pushButton->setAutoDefault(false);
        pushButton->setFlat(false);

        gridLayout_2->addWidget(pushButton, 0, 5, 2, 1);

        pushButton_6 = new QPushButton(groupBox_4);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setMinimumSize(QSize(91, 41));
        pushButton_6->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 66, 101);\n"
"border-radius: 15px;\n"
"font: 900 10pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));

        gridLayout_2->addWidget(pushButton_6, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(groupBox_4);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(91, 41));
        pushButton_2->setMaximumSize(QSize(150, 111));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 66, 101);\n"
"border-radius: 15px;\n"
"font: 900 10pt \"Maven Pro\";\n"
"color: rgb(188, 190, 136);"));

        gridLayout_2->addWidget(pushButton_2, 1, 3, 1, 1);


        gridLayout->addWidget(groupBox_4, 2, 0, 1, 2);

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
        label->setText(QCoreApplication::translate("PlannerPage", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("PlannerPage", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("PlannerPage", "Persian date:", nullptr));
        label_3->setText(QCoreApplication::translate("PlannerPage", "Gregorian date:", nullptr));
        groupBox->setTitle(QCoreApplication::translate("PlannerPage", "Notes", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("PlannerPage", "To-Do list", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("PlannerPage", "Menu", nullptr));
        pushButton_3->setText(QCoreApplication::translate("PlannerPage", "show To-do", nullptr));
        pushButton_7->setText(QCoreApplication::translate("PlannerPage", "delete \n"
"To-do", nullptr));
        pushButton_4->setText(QCoreApplication::translate("PlannerPage", "show Notes", nullptr));
        pushButton_5->setText(QCoreApplication::translate("PlannerPage", "delete \n"
"Note", nullptr));
        pushButton->setText(QCoreApplication::translate("PlannerPage", "first page", nullptr));
        pushButton_6->setText(QCoreApplication::translate("PlannerPage", "Add to To-do", nullptr));
        pushButton_2->setText(QCoreApplication::translate("PlannerPage", "Add to Notes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlannerPage: public Ui_PlannerPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANNERPAGE_H
