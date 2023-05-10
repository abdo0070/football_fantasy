#ifndef UTILS_H
#define UTILS_H
#include<QString>

class utils
{
public:
    static QString get_shirt_path(qint64 club_id);
    static QString get_club_path(qint64 club_id);

    utils();
};

#endif // UTILS_H
