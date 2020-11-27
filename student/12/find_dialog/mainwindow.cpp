#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>

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


void MainWindow::on_fileLineEdit_editingFinished()
{
    file_ = ui->fileLineEdit->text();
}

void MainWindow::on_keyLineEdit_editingFinished()
{
    word_ = ui->keyLineEdit->text();
}

void MainWindow::on_findPushButton_clicked()
{
    QString str = "";
    QFile file(file_);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        str.append("File not found");
    }
    else{
        if(word_.length()==0){
            str.append("File found");
        }
        else{
            QTextStream in(&file);
            QString text = in.readAll();

            if(ui->matchCheckBox->isChecked()){
                if(text.indexOf(word_) == -1){
                    str.append("Word not found");
                }
                else{
                    str.append("Word found");
                }
            }
            else{
                Qt::CaseSensitivity cs= Qt::CaseInsensitive;
                if(text.indexOf(word_, 0, cs) == -1){
                    str.append("Word not found");
                }
                else{
                    str.append("Word found");
                }
            }

        }
    }

    ui->textBrowser->setText(str);
}
