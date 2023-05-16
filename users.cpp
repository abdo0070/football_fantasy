#include "users.h"
#include "data.h"
users::users()
{

}

void users::remove(qint64 id)
{
    d_users.erase(id);
    users::size--;

    qint64 deleted_team;
    teams::size--;
    for(auto i = d_teams.begin(); i != d_teams.end(); i++)
    {
        if(i->second.user_id == id)
        {
            deleted_team = i->first;
            d_teams.erase(i->first);
            break;
        }
    }

    for(auto i = d_teams_players.begin() ; i != d_teams_players.end();)
    {
        i++;
        if(prev(i)->second.team_id == deleted_team)
            d_teams_players.erase(prev(i)->first),teams_players::size--;
    }
}


