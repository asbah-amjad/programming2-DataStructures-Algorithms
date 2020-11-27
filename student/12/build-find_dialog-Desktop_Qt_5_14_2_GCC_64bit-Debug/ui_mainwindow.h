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
#include <QtWidgets/QCheckBox>
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
    QLabel *file;
    QLabel *word;
    QLineEdit *fileLineEdit;
    QLineEdit *keyLineEdit;
    QPushButton *findPushButton;
    QPushButton *closePushButton;
    QCheckBox *matchCheckBox;
    QLabel *label;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        file = new QLabel(centralwidget);
        file->setObjectName(QString::fromUtf8("file"));
        file->setGeometry(QRect(80, 30, 101, 20));
        word = new QLabel(centralwidget);
        word->setObjectName(QString::fromUtf8("word"));
        word->setGeometry(QRect(80, 70, 71, 20));
        fileLineEdit = new QLineEdit(centralwidget);
        fileLineEdit->setObjectName(QString::fromUtf8("fileLineEdit"));
        fileLineEdit->setGeometry(QRect(180, 30, 113, 28));
        keyLineEdit = new QLineEdit(centralwidget);
        keyLineEdit->setObjectName(QString::fromUtf8("keyLineEdit"));
        keyLineEdit->setGeometry(QRect(180, 70, 113, 28));
        findPushButton = new QPushButton(centralwidget);
        findPushButton->setObjectName(QString::fromUtf8("findPushButton"));
        findPushButton->setGeometry(QRect(320, 30, 84, 28));
        closePushButton = new QPushButton(centralwidget);
        closePushButton->setObjectName(QString::fromUtf8("closePushButton"));
        closePushButton->setGeometry(QRect(320, 70, 84, 28));
        matchCheckBox = new QCheckBox(centralwidget);
        matchCheckBox->setObjectName(QString::fromUtf8("matchCheckBox"));
        matchCheckBox->setGeometry(QRect(80, 120, 101, 26));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 150, 111, 20));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(85, 190, 311, 81));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(closePushButton, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        file->setText(QCoreApplication::translate("MainWindow", "Find from file:", nullptr));
        word->setText(QCoreApplication::translate("MainWindow", "Find what:", nullptr));
        findPushButton->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
        closePushButton->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        matchCheckBox->setText(QCoreApplication::translate("MainWindow", "Match case", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Search status:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
