#ifndef MATCHES_H
#define MATCHES_H

#include<QApplication>
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
class matches
{
public:
    qint64 club_1,club_2,round_id,result_of_club1,result_of_club2;
    static int size;
public:
    matches();
};

#endif // MATCHES_H
