#include "dialog.h"
#include "ui_dialog.h"
#include<iostream>
#include"data.h"
#include<QMessageBox>
#include<QTableWidgetItem>
#include<QPushButton>

using namespace std;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->tw_premier_league->hide();
    ui->tw_laLiga->hide();
    ui->tw_egyptian_league->hide();
}

map<QString,qint64>get_id;

void Dialog::refresh() // read the clubs
{
    qint64 count_of_premier = 0,count_of_egyptian = 0,count_of_Laliga = 0;

    for(auto i = d_clubs.begin() ; i != d_clubs.end() ; i++)
    {
        get_id[i->second.name] = i->first;
        switch (i->second.league_id)
        {
        case 1:
        {
            count_of_premier++;
            break;
        }
        case 2:
        {
            count_of_egyptian++;
            break;
        }
        case 3:
        {
            count_of_Laliga++;
            break;
        }
        default:
            break;
        }
    }

    ui->tw_premier_league->setRowCount(count_of_premier);
    ui->tw_egyptian_league->setRowCount(count_of_egyptian);
    ui->tw_laLiga->setRowCount(count_of_Laliga);

    qint64 premier_row = 0,egyptian_row = 0,laliga_row = 0;

    for(auto i = d_clubs.begin() ; i != d_clubs.end() ; i++)
    {
        switch (i->second.league_id)
        {
        case 1:
        {
            ui->tw_premier_league->setItem(premier_row++,0,new QTableWidgetItem(QString(i->second.name)));
            break;
        }
        case 2:
        {
            ui->tw_egyptian_league->setItem(egyptian_row++,0,new QTableWidgetItem(QString(i->second.name)));
            break;
        }
        case 3:
        {
            ui->tw_laLiga->setItem(laliga_row++,0,new QTableWidgetItem(QString(i->second.name)));
            break;
        }
        default:
            break;
        }
    }
}


short chosen_league = 0;

void Dialog::on_pb_Premier_League_clicked()
{
    chosen_league = 1;
    ui->tw_laLiga->hide();
    ui->tw_egyptian_league->hide();
    ui->tw_premier_league->show();

}

void Dialog::on_pb_Egyptian_League_clicked()
{
    chosen_league = 2;
    ui->tw_premier_league->hide();
    ui->tw_laLiga->hide();
    ui->tw_egyptian_league->show();
}

void Dialog::on_pb_LaLiga_clicked()
{
    chosen_league = 3;
    ui->tw_premier_league->hide();
    ui->tw_egyptian_league->hide();
    ui->tw_laLiga->show();

}



void Dialog::on_pushButton_clicked()
{

    QString club;

    switch (chosen_league)
    {
    case 1:
    {
        club = ui->tw_premier_league->currentIndex().data().toString();
        break;
    }
    case 2:
    {
        club = ui->tw_egyptian_league->currentIndex().data().toString();
        break;
    }
    case 3:
    {
        club = ui->tw_laLiga->currentIndex().data().toString();
        break;
    }
    default:
    {
        QMessageBox::warning(this,"Error","you didn't chose any league yet..!");
        return;
    }
    }

    if(club == "")
    {
        QMessageBox::warning(this,"Error","you didn't chose any club yet..!");
        return;
    }

    qint64 club_id = get_id[club];
    QMessageBox::StandardButton conform = QMessageBox::information(this,"ready?","are you sure you want " + club +'?',QMessageBox::Yes,QMessageBox::No);
    if(conform == QMessageBox::Yes)
    {
        d_users[max_users_id].club_id = club_id;
        d_teams[++max_teams_id].user_id = max_users_id;
        QMessageBox::information(this,"good one!","new member of "+ club);
        Dialog::close();
    }
}

Dialog::~Dialog()
{
    delete ui;
}


