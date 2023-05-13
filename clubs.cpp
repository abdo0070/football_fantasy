#include "clubs.h"
#include"data.h"
clubs::clubs()
{

}

void clubs::remove(qint64 id)
{
   // find any player that his club_id equal to the removed club id
    for(auto player = d_players.begin() ; player != d_players.end() ; player++) // O(n^2)
    {
       if(player->first == id)
            players::remove(id);
    }
    d_clubs.erase(id);
    clubs::size--;
}
