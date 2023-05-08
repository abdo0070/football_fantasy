#pragma once

#include <map>
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

extern map<int,clubs> d_clubs;
extern map<int,matches> d_matches;
extern map<int,matches_players> d_matches_players;
extern map<int,players> d_players;
extern map<int,rounds> d_rounds;
extern map<int,teams> d_teams;
extern map<int,teams_players> d_teams_players;
extern map<int,users> d_users;
extern map<int,leagues> d_leagues;
extern QSqlDatabase db;
extern QString current_user;
extern qint64 current_user_id;

extern int max_clubs_id;
extern int max_matches_id;
extern int max_matches_players_id;
extern int max_players_id;
extern int max_rounds_id;
extern int max_teams_id;
extern int max_teams_players_id;
extern int max_users_id;
extern int max_leagues_id;

