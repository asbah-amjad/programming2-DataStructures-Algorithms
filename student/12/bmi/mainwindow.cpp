#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_weightLineEdit_editingFinished()
{
    weight_ = ui->weightLineEdit->text();
}

void MainWindow::on_heightLineEdit_editingFinished()
{
    height_ = ui->heightLineEdit->text();
}

void MainWindow::on_countButton_clicked()
{
    QString str = "";
    double height_m = height_.toDouble() / 100;

    double bmi = weight_.toDouble() / (height_m * height_m);

    if(bmi < 18.5){
        str.append("You are underweight.");
    }
    else if(bmi > 25){
        str.append("You are overweight.");
    }
    else{
        str.append("Your weight is normal.");
    }
    ui->resultLabel->setNum(bmi);
    ui->infoTextBrowser->setText(str);
}
