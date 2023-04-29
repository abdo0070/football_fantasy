#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<stdio.h>
#include<iostream>
#include"data.h"
#include<QMessageBox>
using namespace std;
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

};

MainWindow::~MainWindow()
{
    delete ui;
    QSqlQuery qry;
    cout << "clubs deleted :"<< qry.exec("delete from clubs") << '\n';
    cout << "matches deleted :"<< qry.exec("delete from matches") << '\n';
    cout << "matches_players deleted :"<< qry.exec("delete from matches_players") << '\n';
    cout << "players deleted :"<< qry.exec("delete from players") << '\n';
    cout << "rounds deleted :"<< qry.exec("delete from rounds") << '\n';
    cout << "teams deleted :"<< qry.exec("delete from teams") << '\n';
    cout << "teams_players deleted :"<< qry.exec("delete from teams_players") << '\n';
    cout << "users deleted :"<< qry.exec("delete from users") << '\n';
    cout << "\n";
    for(auto i = d_clubs.begin() ; i != d_clubs.end() ; i++)
    {
        qry.prepare("insert into clubs values(:id,:name);");
        qry.bindValue(":id",i->first);
        qry.bindValue(":name",i->second.name);
        bool x = qry.exec();
        if(x)
            cout << "clubs is in \n";
        else
            qDebug() << qry.lastError() << '\n';
    }
    for(auto i = d_rounds.begin() ; i != d_rounds.end() ; i++)
    {
        qry.prepare("insert into rounds values(:id,:weak);");
        qry.bindValue(":id",i->first);
        qry.bindValue(":weak",i->second.weak);
        bool x = qry.exec();
        if(x)
            cout << "rounds is in \n";
        else
            qDebug() << qry.lastError() << '\n';
    }
    for(auto i = d_matches.begin() ; i != d_matches.end() ; i++)
    {
        qry.prepare("insert into matches values(:id,:club_1,:club_2,:round_id);");
        qry.bindValue(":id",i->first);
        qry.bindValue(":club_1",i->second.club_1);
        qry.bindValue(":club_2",i->second.club_2);
        qry.bindValue(":round_id",i->second.round_id);
        bool x = qry.exec();
        if(x)
            cout << "matches is in \n";
        else
            qDebug() << qry.lastError() << '\n';
    }
    for(auto i = d_players.begin() ; i != d_players.end() ; i++)
    {
        qry.prepare("insert into players values(:id,:image,:age,:price,:position,:club_id,:name);");
        qry.bindValue(":id",i->first);
        qry.bindValue(":image",i->second.image);
        qry.bindValue(":age",i->second.age);
        qry.bindValue(":price",i->second.price);
        qry.bindValue(":position",i->second.position);
        qry.bindValue(":club_id",i->second.club_id);
        qry.bindValue(":name",i->second.name);
        bool x = qry.exec();
        if(x)
            cout << "players is in \n";
        else
            qDebug() << qry.lastError() << '\n';
    }
    for(auto i = d_users.begin() ; i != d_users.end() ; i++)
    {
        qry.prepare("insert into users values(:id,:email,:name,:password,:price,:points,:is_admin,:club_id);");
        qry.bindValue(":id",i->first);
        qry.bindValue(":email",i->second.email);
        qry.bindValue(":name",i->second.username);
        qry.bindValue(":password",i->second.password);
        qry.bindValue(":price",i->second.budget);
        qry.bindValue(":points",i->second.points);
        qry.bindValue(":is_admin",i->second.is_admin);
        qry.bindValue(":club_id",i->second.club_id);
        bool x = qry.exec();
        if(x)
            cout << "users is in \n";
        else
            qDebug() << qry.lastError() << '\n';
    }
    for(auto i = d_teams.begin() ; i != d_teams.end() ; i++)
    {
        qry.prepare("insert into teams values(:id,:user_id);");
        qry.bindValue(":id",i->first);
        qry.bindValue(":user_id",i->second.user_id);
        bool x = qry.exec();
        if(x)
            cout << "teams is in \n";
        else
            qDebug() << qry.lastError() << '\n';
    }
    for(auto i = d_teams_players.begin() ; i != d_teams_players.end() ; i++)
    {
        qry.prepare("insert into teams_players values(:id,:player_id,:team_id);");
        qry.bindValue(":id",i->first);
        qry.bindValue(":player_id",i->second.player_id);
        qry.bindValue(":team_id",i->second.team_id);
        bool x = qry.exec();
        if(x)
            cout << "teams_players is in \n";
        else
            qDebug() << qry.lastError() << '\n';
    }
    for(auto i = d_matches_players.begin() ; i != d_matches_players.end() ; i++)
    {
        qry.prepare("insert into matches_players values(:id,:points,:match_id,:player_id,:round_id);");
        qry.bindValue(":id",i->first);
        qry.bindValue(":points",i->second.points);
        qry.bindValue(":match_id",i->second.match_id);
        qry.bindValue(":player_id",i->second.player_id);
        qry.bindValue(":round_id",i->second.round_id);
        bool x = qry.exec();
        if(x)
            cout << "matches_players is in \n";
        else
            qDebug() << qry.lastError() << '\n';
    }
}



void MainWindow::on_pushButton_clicked()
{
    QString user = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    for(auto i = d_users.begin() ; i != d_users.end() ; i++)
    {
        if(user == i->second.username && password == i->second.password)
            current_user = user;
    }
    if(current_user != "")
    {
        QMessageBox::information(this,"log in","loged in successfully");
        // opening main window
    }
    else
        QMessageBox::warning(this,"log in","invaled username or password");
}


void MainWindow::on_pushButton_3_clicked()
{
    signUpUi.setWindowState(Qt::WindowFullScreen);
    signUpUi.show();
}

