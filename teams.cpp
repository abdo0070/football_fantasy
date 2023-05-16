#include "teams.h"
#include "data.h"
teams::teams()
{

}
qint64 teams::team_id_user(qint64 user_id)
{
    for (auto i = d_teams.begin(); i != d_teams.end(); i++)
    {
        if (i->second.user_id == user_id)
        {
            return i->first;
        }
    }
}
