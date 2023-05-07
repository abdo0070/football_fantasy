#ifndef PLAYERS_H
#define PLAYERS_H
#include<QApplication>
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
class players
{
public:
    qint64 age,price,club_id,points;
    QString image;
    QString position,name;
    static int size;
public:
    players();
};

#endif // PLAYERS_H
