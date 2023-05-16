#include "signup.h"
#include "ui_signup.h"

#include <QMessageBox>
#include<iostream>

#include "data.h"
#include"SUPPORT.cpp"
using namespace std;
SignUp::SignUp(QWidget *parent):
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_pushButton_clicked()
{
    SignUp::close();
}



void SignUp::on_submitButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString email = ui->lineEdit_2->text();
    QString password = ui->lineEdit_3->text();

    if(valed_user(this,username,email,password) && !is_repeated(this,username,email))
    {
        QMessageBox::information(this,"Success","Wellcome to Fantasy premier league!");
        users::size++;

        d_users[++max_users_id].username = username;
        d_users[max_users_id].email = email;
        d_users[max_users_id].password = password;
        d_users[max_users_id].budget = 100000;
        d_users[max_users_id].is_admin = false;
        d_users[max_users_id].points = 0;
        d_users[max_users_id].number_of_players = 0;

        ch_club.setWindowState(Qt::WindowFullScreen);
        ch_club.refresh();
        ch_club.show();
        SignUp::close();
    }
}

