#ifndef TEAMS_PLAYERS_H
#define TEAMS_PLAYERS_H
#include<QApplication>
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
class teams_players
{
public:
    qint64 id,player_id,team_id;
    static int size;
public:
    teams_players();
};

#endif // TEAMS_PLAYERS_H
