#ifndef PLAYERS_H
#define PLAYERS_H
#include<QApplication>
#include<QPixmap>
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
class players
{
public:
    qint64 id,age,price,club_id;
    QPixmap image;
    QString position,name;
    static int size;
public:
    players();
};

#endif // PLAYERS_H
