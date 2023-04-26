#ifndef MATCHES_PLAYERS_H
#define MATCHES_PLAYERS_H
#include<QApplication>
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
class matches_players
{
public:
    qint64 id,points,match_id,player_id,round_id;
    static int size;
public:
    matches_players();
};

#endif // MATCHES_PLAYERS_H
