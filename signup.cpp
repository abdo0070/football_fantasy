#include "signup.h"
#include "ui_signup.h"
#include <QRegularExpression>
#include <QMessageBox>
#include<iostream>
#include "data.h"
#include<QKeyEvent>
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



void SignUp::on_pushButton_2_clicked()
{

    QString username = ui->lineEdit->text();
    QString email = ui->lineEdit_2->text();
    QString password = ui->lineEdit_3->text();

    if(!valed_user(this,username,email,password));
    else
    {
        bool repeated_username = false;
        bool repeated_email = false;

        for(auto i = d_users.begin(); i != d_users.end(); i++)
            if(i->second.username == username)
            {
                repeated_username = true;
                break;
            }
        for(auto i = d_users.begin(); i != d_users.end(); i++)
            if(i->second.email == email)
            {
                repeated_email = true;
                break;
            }
        if(repeated_username)
            QMessageBox::warning(this,"Faild","this username has already been used!");
        else if(repeated_email)
            QMessageBox::warning(this,"Faild","this email has already been used!");
        else
        {
            QMessageBox::information(this,"Success","Wellcome to Fantasy premier league!");
            users::size++;
            d_users[++max_users_id].username = username;
            d_users[max_users_id].email = email;
            d_users[max_users_id].password = password;
            d_users[max_users_id].budget = 100000;
            d_users[max_users_id].is_admin = false;
            d_users[max_users_id].points = 0;
            ch_club.setWindowState(Qt::WindowFullScreen);
            ch_club.show();
            d_users[max_users_id].club_id = ch_club.checked;
            d_users[max_users_id].number_of_players = 0;
            SignUp::close();
        }
    }
}

