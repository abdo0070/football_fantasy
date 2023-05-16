#ifndef TEAMS_H
#define TEAMS_H
#include<QApplication>
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
class teams
{
public:
    qint64 user_id;
    static int size;
    static qint64 team_id_user(qint64 user_id);
public:
    teams();
};

#endif // TEAMS_H
