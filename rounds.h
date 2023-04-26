#ifndef ROUNDS_H
#define ROUNDS_H
#include<QApplication>
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
class rounds
{
public:
    qint64 id;
    QString weak;
    static int size;
public:
    rounds();
};

#endif // ROUNDS_H
