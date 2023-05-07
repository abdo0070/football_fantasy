#include "home.h"
#include "ui_home.h"
#include <QPixmap>
#include"data.h"
#include<iostream>
using namespace std;
Home::Home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    QPixmap profile;
    switch (d_users[current_user_id].club_id)
    {
    case 1:
    {
        profile = QPixmap(":/background/Clubs/Liverpool_FC.svg.png");
        break;
    }
    case 2:
    {
        profile = QPixmap(":/background/Clubs/Chelsea_FC.svg.png");
        break;
    }
    case 3:
    {
        profile = QPixmap(":/background/Clubs/Manchester_City_FC_badge.svg.png");
        break;
    }
    case 4:
    {
        profile = QPixmap(":/background/Clubs/Pyramids_FC_(2020).png");
        break;
    }
    case 5:
    {
        profile = QPixmap(":/background/Clubs/Al_Ahly_SC_logo.png");
        break;
    }
    case 6:
    {
        profile = QPixmap(":/background/Clubs/ZamalekSC.png");
        break;
    }
    case 7:
    {
        profile = QPixmap(":/background/Clubs/FC_Barcelona_(crest).svg.png");
        break;
    }
    case 8:
    {
        profile = QPixmap(":/background/Clubs/Real_Madrid_CF.svg.png");
        break;
    }
    case 9:
    {
        profile = QPixmap(":/background/Clubs/Atletico_Madrid_2017_logo.svg.png");
        break;
    }
    default:
        break;
    }
    ui->label_4->setPixmap(profile);


    ui->tabWidget->setTabVisible(4,d_users[current_user_id].is_admin);
    ui->tabWidget->setTabVisible(0,!d_users[current_user_id].is_admin);
}

Home::~Home()
{
    delete ui;
}

void Home::on_pushButton_clicked()
{
    Home::close();
}


void Home::on_pb_read_clicked()
{
    ui->tableWidget->setRowCount(users::size);

    int rowNum = 0;
    for(auto user = d_users.begin() ; user != d_users.end() ; user++ , rowNum++)
    {
    ui->tableWidget->setItem(rowNum,0,new QTableWidgetItem(QString::number(user->first)));
    ui->tableWidget->setItem(rowNum,1,new QTableWidgetItem(QString(user->second.username)));
    ui->tableWidget->setItem(rowNum,2,new QTableWidgetItem(QString::number(user->second.points)));
    ui->tableWidget->setItem(rowNum,3,new QTableWidgetItem(QString::number(user->second.budget)));
    ui->tableWidget->setItem(rowNum,4,new QTableWidgetItem(QString::number(user->second.is_admin)));
    ui->tableWidget->setItem(rowNum,5,new QTableWidgetItem(QString::number(user->second.club_id)));
    ui->tableWidget->setItem(rowNum,6,new QTableWidgetItem(QString(user->second.email)));

    }

}

