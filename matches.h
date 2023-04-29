#ifndef MATCHES_H
#define MATCHES_H

#include<QApplication>
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
class matches
{
public:
    qint64 club_1,club_2,round_id;
    static int size;
public:
    matches();
};

#endif // MATCHES_H
