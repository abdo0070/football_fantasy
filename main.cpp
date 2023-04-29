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
using namespace std;

map<int,clubs> d_clubs;
map<int,matches> d_matches;
map<int,matches_players> d_matches_players;
map<int,players> d_players;
map<int,rounds> d_rounds;
map<int,teams> d_teams;
map<int,teams_players> d_teams_players;
map<int,users> d_users;


QString current_user;
QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

int clubs::size = 0;
int matches::size = 0;
int matches_players::size = 0;
int players::size = 0;
int rounds::size = 0;
int teams::size = 0;
int teams_players::size = 0;
int users::size = 0;

int main(int argc, char *argv[])
{

    db.setDatabaseName("fantasy");
    db.setHostName("127.0.0.1");
    db.setPassword("@#191#36@aC");
    db.setUserName("root");

    db.open();



    QSqlQuery qry;
    bool d0 = qry.exec("SELECT * FROM clubs;");
    while(qry.next())
    {
        clubs::size = qry.size();
        int key = qry.value(0).toInt();
        d_clubs[key].name = qry.value(1).toString();
    }
    bool d1 = qry.exec("SELECT * FROM matches;");
    while(qry.next())
    {
        matches::size = qry.size();
        int key = qry.value(0).toInt();
        d_matches[key].club_1 = qry.value(1).toInt();
        d_matches[key].club_2 = qry.value(2).toInt();
        d_matches[key].round_id = qry.value(3).toInt();
    }
    bool d2 = qry.exec("SELECT * FROM matches_players;");
    while(qry.next())
    {
        matches_players::size = qry.size();
        int key = qry.value(0).toInt();
        d_matches_players[key].points = qry.value(1).toInt();
        d_matches_players[key].match_id = qry.value(2).toInt();
        d_matches_players[key].player_id = qry.value(3).toInt();
        d_matches_players[key].round_id = qry.value(4).toInt();
    }
    bool d3 = qry.exec("SELECT * FROM players;");
    while(qry.next())
    {
        players::size = qry.size();
        int key = qry.value(0).toInt();
        d_players[key].image = qry.value(1).toString(); // the path
        d_players[key].age = qry.value(2).toInt();
        d_players[key].price = qry.value(3).toInt();
        d_players[key].position = qry.value(4).toString();
        d_players[key].club_id = qry.value(5).toInt();
        d_players[key].name = qry.value(6).toString();
    }
    bool d4 = qry.exec("SELECT * FROM rounds;");
    while(qry.next())
    {
        rounds::size = qry.size();
        int key = qry.value(0).toInt();
        d_rounds[key].weak = qry.value(1).toString();
    }
    bool d5 = qry.exec("SELECT * FROM teams;");
    while(qry.next())
    {
        teams::size = qry.size();
        int key = qry.value(0).toInt();
        d_teams[key].user_id = qry.value(1).toInt();
    }
    bool d6 = qry.exec("SELECT * FROM teams_players;");
    while(qry.next())
    {
        teams_players::size = qry.size();
        int key = qry.value(0).toInt();
        d_teams_players[key].player_id = qry.value(1).toInt();
        d_teams_players[key].team_id = qry.value(2).toInt();
    }
    bool d7 = qry.exec("SELECT * FROM users;");
    while(qry.next())
    {
        users::size = qry.size();
        int key = qry.value(0).toInt();
        d_users[key].email = qry.value(1).toString();
        d_users[key].username = qry.value(2).toString();
        d_users[key].password = qry.value(3).toString();
        d_users[key].budget = qry.value(4).toInt();
        d_users[key].points = qry.value(5).toInt();
        d_users[key].is_admin = qry.value(6).toBool();
        d_users[key].club_id = qry.value(7).toInt();
    }
    // data is ready
    cout << d0 << endl << d1 << endl << d2 << endl << d3 << endl << d4 << endl << d5 << endl << d6 << endl << d7 << endl;
    QApplication a(argc, argv);

    MainWindow w;
    w.setWindowState(Qt::WindowFullScreen);
    w.show();

    return a.exec();
}
