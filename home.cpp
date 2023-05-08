#include "home.h"
#include "ui_home.h"
#include <QPixmap>
#include"data.h"
#include<iostream>
#include<QMessageBox>

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

    // hide delete users
        ui->l_enter_id->hide();
        ui->le_enter_id->hide();
        ui->pb_conform->hide();
    // hide insert users
        ui->le_username->hide();
        ui->le_email->hide();
        ui->le_password->hide();
        ui->le_budget->hide();
        ui->le_points->hide();
        ui->l_choose_club->hide();
        ui->is_admin->hide();
        ui->cb_club->hide();
        ui->pb_conform_insert->hide();
    // hide update users
        ui->le_target_id->hide();
        ui->le_username_update->hide();
        ui->le_email_update->hide();
        ui->le_password_update->hide();
        ui->le_budget_update->hide();
        ui->le_points_update->hide();
        ui->l_choose_club_update->hide();
        ui->is_admin_update->hide();
        ui->cb_club_update->hide();
        ui->pb_conform_update->hide();
        ui->l_update->hide();
        ui->cb_update_username->hide();
        ui->cb_update_email->hide();
        ui->cb_update_password->hide();
        ui->cb_update_budget->hide();
        ui->cb_update_points->hide();
        ui->cb_update_club->hide();
        ui->cb_update_admin->hide();

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

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



void Home::on_pb_delete_clicked()
{
    if(!ui->le_enter_id->isVisible())
    {
        ui->l_enter_id->show();
        ui->le_enter_id->show();
        ui->pb_conform->show();
    }
    else
    {
        ui->l_enter_id->hide();
        ui->le_enter_id->hide();
        ui->pb_conform->hide();
    }
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
    bool valed = false;
    for(auto i = d_users.begin() ; i != d_users.end() ; i++)
        if(i->first == deleted_id)
        {
            valed = true;
            break;
        }
    if(valed)
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
    if(!ui->le_username->isVisible())
    {
        ui->le_username->show();
        ui->le_email->show();
        ui->le_password->show();
        ui->le_budget->show();
        ui->le_points->show();
        ui->l_choose_club->show();
        ui->is_admin->show();
        ui->cb_club->show();
        ui->pb_conform_insert->show();
    }
    else
    {
        ui->le_username->hide();
        ui->le_email->hide();
        ui->le_password->hide();
        ui->le_budget->hide();
        ui->le_points->hide();
        ui->l_choose_club->hide();
        ui->is_admin->hide();
        ui->cb_club->hide();
        ui->pb_conform_insert->hide();
    }
}


void Home::on_pb_conform_insert_clicked()
{
    bool valed1 = false,valed2 = true;
    if(!ui->le_username->text().isEmpty()
        && !ui->le_email->text().isEmpty()
        && !ui->le_password->text().isEmpty()
        && !ui->le_budget->text().isEmpty()
        && !ui->le_points->text().isEmpty()
        )
        valed1 = true;
    for(auto i = d_users.begin() ; i != d_users.end() ; i ++)
    {
        if(i->second.username == ui->le_username->text() || i->second.email == ui->le_email->text() )
        {
            valed2 = false;
            break;
        }
    }
    if(valed1 && valed2)
    {
        users::size++;
        d_users[++max_users_id].username = ui->le_username->text();
        d_users[max_users_id].email = ui->le_email->text();
        d_users[max_users_id].password = ui->le_password->text();
        d_users[max_users_id].budget = ui->le_budget->text().toInt();
        d_users[max_users_id].points = ui->le_points->text().toInt();
        d_users[max_users_id].is_admin = ui->is_admin->isChecked();
        d_users[max_users_id].number_of_players = 0;
        d_users[max_users_id].club_id = (ui->cb_club->currentIndex())+1;
    }
    else if(!valed1)
        QMessageBox::critical(this,"Error","invaled data!");
    else
        QMessageBox::critical(this,"Error","repeated username or email!");
    on_pb_read_clicked();
}

void Home::on_pb_update_clicked()
{
    if(!ui->le_username_update->isVisible())
    {
        ui->le_target_id->show();
        ui->l_update->show();
        ui->le_username_update->show();
        ui->le_email_update->show();
        ui->le_password_update->show();
        ui->le_budget_update->show();
        ui->le_points_update->show();
        ui->l_choose_club_update->show();
        ui->is_admin_update->show();
        ui->cb_club_update->show();
        ui->pb_conform_update->show();
        ui->cb_update_username->show();
        ui->cb_update_email->show();
        ui->cb_update_password->show();
        ui->cb_update_budget->show();
        ui->cb_update_points->show();
        ui->cb_update_club->show();
        ui->cb_update_admin->show();
    }
    else
    {
        ui->le_target_id->hide();
        ui->l_update->hide();
        ui->le_username_update->hide();
        ui->le_email_update->hide();
        ui->le_password_update->hide();
        ui->le_budget_update->hide();
        ui->le_points_update->hide();
        ui->l_choose_club_update->hide();
        ui->is_admin_update->hide();
        ui->cb_club_update->hide();
        ui->pb_conform_update->hide();
        ui->cb_update_username->hide();
        ui->cb_update_email->hide();
        ui->cb_update_password->hide();
        ui->cb_update_budget->hide();
        ui->cb_update_points->hide();
        ui->cb_update_club->hide();
        ui->cb_update_admin->hide();
    }
}
