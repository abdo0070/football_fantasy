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
using namespace std;
extern map<int,clubs> d_clubs;
extern map<int,matches>d_matches;
extern map<int,matches_players>d_matches_players;
extern map<int,players>d_players;
extern map<int,rounds>d_rounds;
extern map<int,teams>d_teams;
extern map<int,teams_players>d_teams_players;
extern map<int,users>d_users;
extern QSqlDatabase db;
extern QString current_user;
