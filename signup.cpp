#include "signup.h"
#include "ui_signup.h"
#include <QRegularExpression>
#include <QMessageBox>
#include<iostream>
#include "data.h"
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
    QRegularExpression email_pattern1("^[\\w._%+-]{1,20}@[\\w.-]{2,20}\\.[A-Za-z]{2,3}");
    QRegularExpression email_pattern2("\\s");

    QRegularExpression password_pattern("\\D+");


    QString username = ui->lineEdit->text();
    QString email = ui->lineEdit_2->text();
    QString password = ui->lineEdit_3->text();

    QRegularExpressionMatch match1_email = email_pattern1.match(email);
    QRegularExpressionMatch match2_email = email_pattern2.match(email);

    QRegularExpressionMatch match_password = password_pattern.match(password);

    if(username.size() > 10 || username.size() < 4 )//password.size() > 8 && password.size() < 16 && match_email.hasMatch() && match_password1.hasMatch() && match_password2.hasMatch())
        QMessageBox::warning(this,"Faild","username size must be greater than 3 chracters and less than 11");
    else if(!match1_email.hasMatch() || match2_email.hasMatch())
        QMessageBox::warning(this,"Faild","email doesn't match \n note that only gmail domain is valed");
    else if(!match_password.hasMatch())
        QMessageBox::warning(this,"Faild","password doesn't match \n note that you have to use at least one chracter!\n the size of your password must be greater than 8 and less than 16!");
    else if(password.size() < 8 || password.size() > 16 || !match_password.hasMatch())
        QMessageBox::warning(this,"Faild","password size must be greater than 7 chracters and less than 17 \n note that password must have at least one special character");
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

            d_users[++users::size].username = username;
            d_users[users::size].email = email;
            d_users[users::size].password = password;
            d_users[users::size].budget = 100000;
            d_users[users::size].is_admin = false;
            d_users[users::size].points = 0;
            ch_club.setWindowState(Qt::WindowFullScreen);
            ch_club.show();
            d_users[users::size].club_id = ch_club.checked;
            d_users[users::size].number_of_players = 0;
            SignUp::close();
        }
    }
}

