#include "dialog.h"
#include "ui_dialog.h"
#include<iostream>
#include"data.h"
#include<QMessageBox>
using namespace std;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked())
        checked = 7;
    else if(ui->radioButton_2->isChecked())
        checked = 8;
    else if(ui->radioButton_3->isChecked())
        checked = 9;
    else if(ui->radioButton_4->isChecked())
        checked = 1;
    else if(ui->radioButton_5->isChecked())
        checked = 2;
    else if(ui->radioButton_6->isChecked())
        checked = 3;
    else if(ui->radioButton_7->isChecked())
        checked = 5;
    else if(ui->radioButton_8->isChecked())
        checked = 4;
    else
        checked = 6;
    d_users[max_users_id].club_id = checked;
    QMessageBox config;
    config.information(this,"good one!","new member of "+ d_clubs[checked].name);
    Dialog::close();
}

