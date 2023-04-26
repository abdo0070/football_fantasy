#ifndef TEAMS_H
#define TEAMS_H
#include<QApplication>
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
class teams
{
public:
    qint64 id,user_id;
    static int size;
public:
    teams();
};

#endif // TEAMS_H
