/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *weightLineEdit;
    QLineEdit *heightLineEdit;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *countButton;
    QLabel *label_5;
    QLabel *label_6;
    QTextBrowser *infoTextBrowser;
    QPushButton *closeButton;
    QLabel *resultLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 30, 63, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 60, 63, 20));
        weightLineEdit = new QLineEdit(centralwidget);
        weightLineEdit->setObjectName(QString::fromUtf8("weightLineEdit"));
        weightLineEdit->setGeometry(QRect(200, 20, 113, 28));
        heightLineEdit = new QLineEdit(centralwidget);
        heightLineEdit->setObjectName(QString::fromUtf8("heightLineEdit"));
        heightLineEdit->setGeometry(QRect(200, 60, 113, 28));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(320, 20, 63, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(320, 60, 63, 20));
        countButton = new QPushButton(centralwidget);
        countButton->setObjectName(QString::fromUtf8("countButton"));
        countButton->setGeometry(QRect(100, 100, 84, 28));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(110, 150, 63, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(110, 190, 63, 20));
        infoTextBrowser = new QTextBrowser(centralwidget);
        infoTextBrowser->setObjectName(QString::fromUtf8("infoTextBrowser"));
        infoTextBrowser->setGeometry(QRect(190, 180, 201, 71));
        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(90, 240, 84, 28));
        resultLabel = new QLabel(centralwidget);
        resultLabel->setObjectName(QString::fromUtf8("resultLabel"));
        resultLabel->setGeometry(QRect(220, 150, 63, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(closeButton, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Weight:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Height:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "kg", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "cm", nullptr));
        countButton->setText(QCoreApplication::translate("MainWindow", "Count", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "BMI:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Info:", nullptr));
        closeButton->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        resultLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
