#ifndef USERS_H
#define USERS_H
#include<QApplication>
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
class users
{
public:
    qint64 budget,points,club_id,number_of_players;
    bool is_admin;
    QString username,email,password;
    static int size;

public:
    static void remove(qint64 id);

    users();
};

#endif // USERS_H

