#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(timer, &QTimer::timeout, this, &MainWindow::showTime);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    if(timer->isActive()){
        return;
    }
    else{
        timer->start(6000);
    }

    showTime();
}

void MainWindow::on_stopButton_clicked()
{
    if(timer->isActive()){
        timer->stop();
    }
}

void MainWindow::on_resetButton_clicked()
{

}

void MainWindow::showTime()
{
    QTime time = QTime::currentTime();
    int sec = time.second();
    int min = time.minute();
    ui->lcdNumberMin->display(min);
    ui->lcdNumberSec->display(sec);
}
