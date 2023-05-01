#ifndef CLUBS_H
#define CLUBS_H
#include <QApplication>
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
class clubs
{
public:
    static int size;
    qint64 league_id;
    QString name;
public:
    clubs();
};

#endif // CLUBS_H
