#include <QRegularExpression>
#include <QMessageBox>
#include "data.h"
template<class T>
bool valed_user(T THIS,QString username,QString email,QString password)
{
    QRegularExpression email_pattern1("^[\\w._%+-]{1,20}@[\\w.-]{2,20}\\.[A-Za-z]{2,3}");
    QRegularExpression email_pattern2("\\s");
    QRegularExpression password_pattern("\\D+");
    QRegularExpressionMatch match1_email = email_pattern1.match(email);
    QRegularExpressionMatch match2_email = email_pattern2.match(email);
    QRegularExpressionMatch match_password = password_pattern.match(password);
    if(username.size() > 10 || username.size() < 4)
    {
        QMessageBox::warning(THIS,"Faild","username size must be greater than 3 chracters and less than 11");
        return false;
    }
    else if(!match1_email.hasMatch() || match2_email.hasMatch())
    {
        QMessageBox::warning(THIS,"Faild","email doesn't match \n note that only gmail domain is valed");
        return false;
    }
    else if(!match_password.hasMatch())
    {
        QMessageBox::warning(THIS,"Faild","password doesn't match \n note that you have to use at least one chracter!\n the size of your password must be greater than 8 and less than 16!");
        return false;
    }
    else if(password.size() < 8 || password.size() > 16 || !match_password.hasMatch())
    {
        QMessageBox::warning(THIS,"Faild","password size must be greater than 7 chracters and less than 17 \n note that password must have at least one special character");
        return false;
    }

    return true;
}

template<class T>
bool is_repeated(T THIS,QString username,QString email)
{
    for(auto i = d_users.begin(); i != d_users.end(); i++)
        if(i->second.username == username)
        {
            QMessageBox::warning(THIS,"Faild","this username has already been used!");
            return true;
        }
    for(auto i = d_users.begin(); i != d_users.end(); i++)
        if(i->second.email == email)
        {
            QMessageBox::warning(THIS,"Faild","this email has already been used!");
            return true;
        }
    return false;
}

template<class T>
bool is_found(int id,map<int,T> d_table)
{
    for(auto i = d_table.begin(); i != d_table.end(); i++)
        if(id == i->first)
            return true;
    return false;
}


