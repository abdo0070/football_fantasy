#include "mainwindow.h"
#include <QApplication>
#include <iostream>

#include "clubs.h"
#include "matches.h"
#include "matches_players.h"
#include "players.h"
#include "rounds.h"
#include "teams.h"
#include "teams_players.h"
#include "users.h"
#include "leagues.h"

using namespace std;

map<int,clubs> d_clubs;
map<int,matches> d_matches;
map<int,matches_players> d_matches_players;
map<int,players> d_players;
map<int,rounds> d_rounds;
map<int,teams> d_teams;
map<int,teams_players> d_teams_players;
map<int,users> d_users;
map<int,leagues> d_leagues;

QString current_user;
qint64 current_user_id;

QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

int clubs::size = 0;
int matches::size = 0;
int matches_players::size = 0;
int players::size = 0;
int rounds::size = 0;
int teams::size = 0;
int teams_players::size = 0;
int users::size = 0;
int leagues::size = 0;

int max_clubs_id = 0;
int max_matches_id = 0;
int max_matches_players_id = 0;
int max_players_id = 0;
int max_rounds_id = 0;
int max_teams_id = 0;
int max_teams_players_id = 0;
int max_users_id = 0;
int max_leagues_id = 0;

int main(int argc, char *argv[])
{

    db.setDatabaseName("fantasy");
    db.setHostName("127.0.0.1");
    db.setPassword("@#191#36@aC");
    db.setUserName("root");

    db.open();

    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowState(Qt::WindowFullScreen);
    w.show();

    return a.exec();
}
