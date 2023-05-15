#include "clubs.h"
#include"data.h"
clubs::clubs()
{

}

void clubs::remove(qint64 id)
{
    // find any player that his club_id equal to the removed club id
    for(auto player = d_players.begin() ; player != d_players.end() ;) // O(n^2)
    {
        player++;
        if(prev(player)->second.club_id == id)
           players::remove(prev(player)->first);
    }
    for(auto match = d_matches.begin() ; match != d_matches.end() ;)
    {
       match++;
       if(prev(match)->second.club_1 == id || prev(match)->second.club_2 == id)
       {
            matches::size--;
            d_matches.erase(prev(match)->first);
       }
    }
    d_clubs.erase(id);
    clubs::size--;
    for (auto user = d_users.begin() ; user != d_users.end() ; user++)
    {
       if(user->second.club_id == id)
            user->second.club_id = d_clubs.begin()->first; // as it will be the default
    }
}

qint64 clubs::find_id(QString club)
{
    for(auto i = d_clubs.begin() ; i != d_clubs.end() ; i++)
       if(club == i->second.name)
            return i->first;
}
