#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::showTime);

    //showTime();
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
        timer->start(1000);
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
    QTime time = QTime::fromString("0.0", "m.s");
    int sec = time.second();
    int min = time.minute();
    ui->lcdNumberMin->display(min);
    ui->lcdNumberSec->display(sec);
}

void MainWindow::showTime()
{
    QTime time = QTime::fromString("0.6", "m.s");
    int sec = time.second();
    int min = time.minute();
    ui->lcdNumberMin->display(min);
    ui->lcdNumberSec->display(sec);
}
