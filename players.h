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
    QString position,name;
    static int size;
public:
    players();
    static void remove(qint64 id);
};

#endif // PLAYERS_H
