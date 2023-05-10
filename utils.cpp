#include "utils.h"
#include"data.h"

utils::utils()
{

}

QString utils::get_shirt_path(qint64 club_id)
{
    QString club = ":/background/shirts/";
    club += d_clubs[club_id].name + ".png";
    return club;
}
QString utils::get_club_path(qint64 club_id)
{
    QString club = ":/background/Clubs/";
    club += d_clubs[club_id].name + ".png";
    return club;
}
