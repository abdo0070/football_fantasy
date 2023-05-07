#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<QMessageBox>
#include"data.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlQuery qry;
    bool d0 = qry.exec("SELECT * FROM leagues;");
    while(qry.next())
    {
        leagues::size = qry.size();
        int key = qry.value(0).toInt();
        d_leagues[key].name = qry.value(1).toString();
    }
    bool d1 = qry.exec("SELECT * FROM clubs;");
    while(qry.next())
    {
        clubs::size = qry.size();
        int key = qry.value(0).toInt();
        d_clubs[key].name = qry.value(1).toString();
        d_clubs[key].league_id = qry.value(2).toInt();
    }
    bool d2 = qry.exec("SELECT * FROM matches;");
    while(qry.next())
    {
        matches::size = qry.size();
        int key = qry.value(0).toInt();
        d_matches[key].club_1 = qry.value(1).toInt();
        d_matches[key].club_2 = qry.value(2).toInt();
        d_matches[key].round_id = qry.value(3).toInt();
    }
    bool d3 = qry.exec("SELECT * FROM matches_players;");
    while(qry.next())
    {
        matches_players::size = qry.size();
        int key = qry.value(0).toInt();
        d_matches_players[key].points = qry.value(1).toInt();
        d_matches_players[key].match_id = qry.value(2).toInt();
        d_matches_players[key].player_id = qry.value(3).toInt();
        d_matches_players[key].round_id = qry.value(4).toInt();
    }
    bool d4 = qry.exec("SELECT * FROM players;");
    while(qry.next())
    {
        players::size = qry.size();
        int key = qry.value(0).toInt();
        d_players[key].age = qry.value(1).toInt();
        d_players[key].price = qry.value(2).toInt();
        d_players[key].position = qry.value(3).toString();
        d_players[key].club_id = qry.value(4).toInt();
        d_players[key].name = qry.value(5).toString();
        d_players[key].points = qry.value(6).toInt();
    }
    bool d5 = qry.exec("SELECT * FROM rounds;");
    while(qry.next())
    {
        rounds::size = qry.size();
        int key = qry.value(0).toInt();
        d_rounds[key].weak = qry.value(1).toString();
    }
    bool d6 = qry.exec("SELECT * FROM teams;");
    while(qry.next())
    {
        teams::size = qry.size();
        int key = qry.value(0).toInt();
        d_teams[key].user_id = qry.value(1).toInt();
    }
    bool d7 = qry.exec("SELECT * FROM teams_players;");
    while(qry.next())
    {
        teams_players::size = qry.size();
        int key = qry.value(0).toInt();
        d_teams_players[key].player_id = qry.value(1).toInt();
        d_teams_players[key].team_id = qry.value(2).toInt();
    }
    bool d8 = qry.exec("SELECT * FROM users;");
    while(qry.next())
    {
        users::size = qry.size();
        int key = qry.value(0).toInt();
        d_users[key].email = qry.value(1).toString();
        d_users[key].username = qry.value(2).toString();
        d_users[key].password = qry.value(3).toString();
        d_users[key].budget = qry.value(4).toInt();
        d_users[key].points = qry.value(5).toInt();
        d_users[key].is_admin = qry.value(6).toBool();
        d_users[key].club_id = qry.value(7).toInt();
        d_users[key].number_of_players = qry.value(8).toInt();
    }

    // data is ready
    cout << d0 << endl
         << d1 << endl
         << d2 << endl
         << d3 << endl
         << d4 << endl
         << d5 << endl
         << d6 << endl
         << d7 << endl
         << d8 << endl;
};

MainWindow::~MainWindow()
{
    delete ui;
    QSqlQuery qry;
    cout << "clubs deleted :" << qry.exec("delete from clubs;") << '\n';
    cout << "leagues deleted :" << qry.exec("delete from leagues;")<< '\n';
    cout << "matches deleted :"<< qry.exec("delete from matches;") << '\n';
    cout << "matches_players deleted :" << qry.exec("delete from matches_players;") << '\n';
    cout << "players deleted :" << qry.exec("delete from players;") << '\n';
    cout << "rounds deleted :" << qry.exec("delete from rounds;") << '\n';
    cout << "teams deleted :" << qry.exec("delete from teams;") << '\n';
    cout << "teams_players deleted :" << qry.exec("delete from teams_players;") << '\n';
    cout << "users deleted :" << qry.exec("delete from users;") << '\n';

    cout << "\n";
    int y = 0;
    for(auto i = d_leagues.begin() ; i != d_leagues.end() ; i++)
    {
        qry.prepare("insert into leagues values(:id,:name);");
        qry.bindValue(":id",i->first);
        qry.bindValue(":name",i->second.name);
        bool x = qry.exec();
        if(x)
            cout << "leagues is in \n";
        else
            qDebug() << y << '\n' << qry.lastError() << '\n';
    }
    for(auto i = d_clubs.begin() ; i != d_clubs.end() ; i++,y++)
    {
        qry.prepare("insert into clubs values(:id,:name,:league_id);");
        qry.bindValue(":id",i->first);
        qry.bindValue(":name",i->second.name);
        qry.bindValue(":league_id",i->second.league_id);
        bool x = qry.exec();
        if(x)
            cout << "clubs is in \n";
        else
            qDebug() << "\n" << y << "\n" << qry.lastError() << '\n';
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
        qry.prepare("insert into players values(:id,:age,:price,:position,:club_id,:name,:points);");
        qry.bindValue(":id",i->first);
        qry.bindValue(":age",i->second.age);
        qry.bindValue(":price",i->second.price);
        qry.bindValue(":position",i->second.position);
        qry.bindValue(":club_id",i->second.club_id);
        qry.bindValue(":name",i->second.name);
        qry.bindValue(":points",i->second.points);
        bool x = qry.exec();
        if(x)
            cout << "players is in \n";
        else
            qDebug() << qry.lastError() << '\n';
    }
    for(auto i = d_users.begin() ; i != d_users.end() ; i++)
    {
        qry.prepare("insert into users values(:id,:email,:name,:password,:price,:points,:is_admin,:club_id,:number_of_players);");
        qry.bindValue(":id",i->first);
        qry.bindValue(":email",i->second.email);
        qry.bindValue(":name",i->second.username);
        qry.bindValue(":password",i->second.password);
        qry.bindValue(":price",i->second.budget);
        qry.bindValue(":points",i->second.points);
        qry.bindValue(":is_admin",i->second.is_admin);
        qry.bindValue(":club_id",i->second.club_id);
        qry.bindValue(":number_of_players",i->second.number_of_players);
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
        {
            current_user = user,current_user_id=i->first;
            // if there is any data to be calculated before we begin
            break;
        }
    }
    if(current_user != "")
    {
        homeui = new Home;

        QMessageBox::information(this,"log in","loged in successfully");
        homeui->setWindowState(Qt::WindowFullScreen);
        homeui->show();
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
    }
    else
        QMessageBox::warning(this,"log in","invaled username or password");
}

void MainWindow::on_pushButton_3_clicked()
{
    signUpUi.setWindowState(Qt::WindowFullScreen);
    signUpUi.show();
}

void MainWindow::on_pushButton_2_clicked()
{
    MainWindow::close();
}

