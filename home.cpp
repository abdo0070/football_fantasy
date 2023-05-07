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
}

Home::~Home()
{
    delete ui;
}

void Home::on_pushButton_clicked()
{
    Home::close();
}

