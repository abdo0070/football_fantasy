#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<stdio.h>
#include<iostream>
#include"data.h"
#include<QMessageBox>
using namespace std;
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

};

MainWindow::~MainWindow()
{
    delete ui;
}









void MainWindow::on_pushButton_clicked()
{
    QString user = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    for(auto i = d_users.begin() ; i != d_users.end() ; i++)
    {
        if(user == i->second.username && password == i->second.password)
        {
            QMessageBox::information(this,"log in","loged in successfully");

        }
        else if(user == i->second.username)
            QMessageBox::warning(this,"log in","password is not correct");
        else if(password == i->second.password)
            QMessageBox::warning(this,"log in","username is not correct");
        else
            QMessageBox::warning(this,"log in","Who are you?");
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    //MainWindow::hide();
    signUpUi.setWindowState(Qt::WindowFullScreen);

    signUpUi.show();

}

