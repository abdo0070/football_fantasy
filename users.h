#ifndef USERS_H
#define USERS_H
#include<QApplication>
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
class users
{
public:
    qint64 id,budget,points,club_id;
    bool is_admin;
    QString username,email,password;
    static int size;

public:
    users();
};

#endif // USERS_H
