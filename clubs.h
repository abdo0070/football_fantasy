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
    QString name,shirt_image,club_image;
public:
    static void refresh();
    clubs();
};

#endif // CLUBS_H
