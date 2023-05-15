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
    static qint64 find_id(QString name);
    static void remove(qint64 id);
    clubs();
};

#endif // CLUBS_H
