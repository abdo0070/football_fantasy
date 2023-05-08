#include "home.h"
#include "ui_home.h"
#include <QPixmap>
#include"data.h"
#include<iostream>
#include<QMessageBox>

using namespace std;

bool Home::find_user(qint64 id)
{
    for(auto i = d_users.begin() ; i != d_users.end() ; i++)
        if(i->first == id)
             return true;
    return false;
}

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

    ui->gb_user_update->hide();
    // hide delete users
        ui->gb_user_delete->hide();
    // hide insert users
        ui->gb_user_insert->hide();
    // hide update users
        ui->gb_user_update->hide();

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->sb_budget_update->setMaximum(10000000);
    ui->sb_budget_insert->setMaximum(10000000);
    ui->sb_points_insert->setMaximum(1000);
    ui->sb_points_update->setMaximum(1000);
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
//    if(ui->pb_read->text() == "READ DATA")
//        ui->pb_read->setText("HIDE DATA");
//    else
//        ui->pb_read->setText("READ DATA");
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



void Home::on_pb_delete_clicked()
{
    if(!ui->le_enter_id->isVisible())
        ui->gb_user_delete->show();
    else
        ui->gb_user_delete->hide();
}


void Home::on_pb_conform_clicked()
{
    qint64 deleted_id = ui->le_enter_id->text().toInt();
    if(ui->le_enter_id->text().isEmpty())
        return;
    if(deleted_id == current_user_id)
    {
        QMessageBox::critical(this,"Faild","You Can NOT delete Yourself!!");
        return;
    }
    if(find_user(deleted_id))
    {
        QMessageBox::warning(this,"deleted",d_users[deleted_id].username+" has been deleted successfully!");
        d_users.erase(deleted_id);
        users::size--;
        on_pb_read_clicked();
    }
    else
        QMessageBox::critical(this,"Error","there is no user with this id..!");
}


void Home::on_pb_insert_clicked()
{
    if(!ui->le_username_insert->isVisible())
        ui->gb_user_insert->show();
    else
        ui->gb_user_insert->hide();
}


void Home::on_pb_conform_insert_clicked()
{
    bool valed1 = false,valed2 = true;
    if(!ui->le_username_insert->text().isEmpty()
        && !ui->le_email_insert->text().isEmpty()
        && !ui->le_password_insert->text().isEmpty()
        && !ui->sb_budget_insert->text().isEmpty()
        && !ui->sb_points_insert->text().isEmpty()
        )
        valed1 = true;
    for(auto i = d_users.begin() ; i != d_users.end() ; i ++)
    {
        if(i->second.username == ui->le_username_insert->text() || i->second.email == ui->le_email_insert->text() )
        {
            valed2 = false;
            break;
        }
    }
    if(valed1 && valed2)
    {
        users::size++;
        d_users[++max_users_id].username = ui->le_username_insert->text();
        d_users[max_users_id].email = ui->le_email_insert->text();
        d_users[max_users_id].password = ui->le_password_insert->text();
        d_users[max_users_id].budget = ui->sb_budget_insert->text().toInt();
        d_users[max_users_id].points = ui->sb_points_insert->text().toInt();
        d_users[max_users_id].is_admin = ui->is_admin_insert->isChecked();
        d_users[max_users_id].number_of_players = 0;
        d_users[max_users_id].club_id = (ui->cb_club_insert->currentIndex())+1;
        QMessageBox::information(this,"success","done!");
        on_pb_read_clicked();
    }
    else if(!valed1)
        QMessageBox::critical(this,"Error","invaled data!");
    else
        QMessageBox::critical(this,"Error","repeated username or email!");
}

void Home::on_pb_update_clicked()
{
    if(!ui->le_username_update->isVisible())
        ui->gb_user_update->show();
    else
        ui->gb_user_update->hide();
}

void Home::on_pb_user_update_clicked()
{
    qint64 id = ui->le_target_id->text().toInt();
    if(!find_user(id))
    {
        QMessageBox::critical(this,"Error","there is no user with this id..!");
            return;
    }
    ui->le_username_update->setText(d_users[id].username);
    ui->le_email_update->setText(d_users[id].email);
    ui->le_password_update->setText(d_users[id].password);
    ui->sb_budget_update->setValue(d_users[id].budget);
    ui->sb_points_update->setValue(d_users[id].points);
    ui->cb_club_update->setCurrentIndex(d_users[id].club_id-1);
    ui->is_admin_update->setChecked(d_users[id].is_admin);
}

void Home::on_pb_conform_update_clicked()
{
    qint64 id = ui->le_target_id->text().toInt();
    if(!find_user(id))
    {
        QMessageBox::critical(this,"Error","there is no user with this id..!");
    }
    d_users[id].username = ui->le_username_update->text();
    d_users[id].email = ui->le_email_update->text();
    d_users[id].password = ui->le_password_update->text();
    d_users[id].budget = ui->sb_budget_update->value();
    d_users[id].points = ui->sb_points_update->value();
    d_users[id].club_id = ui->cb_club_update->currentIndex()+1;
    d_users[id].is_admin = ui->is_admin_update->isChecked();
    QMessageBox::information(this,"success","done!");
    on_pb_read_clicked();
}




