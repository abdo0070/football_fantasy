#include "players.h"
#include"data.h"
players::players()
{

}
void players::remove(qint64 id)
{
    for(auto i = d_matches_players.begin(); i != d_matches_players.end();)
    {
        i++;
        if(prev(i)->second.player_id == id)
        {
            d_matches_players.erase(prev(i)->first);
            matches_players::size--;
        }
    }
    for(auto i = d_teams_players.begin() ; i != d_teams_players.end();) // different users have the same player
    {
        i++;
        if(prev(i)->second.player_id == id)
        {
            d_users[d_teams[prev(i)->second.team_id].user_id].budget += d_players[prev(i)->second.player_id].price;
            d_teams_players.erase(prev(i)->first);
            d_users[d_teams[prev(i)->second.team_id].user_id].number_of_players--;
            teams_players::size--;
        }
    }
    d_players.erase(id);
    players::size--;
}
