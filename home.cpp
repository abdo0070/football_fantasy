#include "home.h"
#include "ui_home.h"
#include <QPixmap>
#include"data.h"
#include<iostream>
#include<QMessageBox>
#include"SUPPORT.cpp"
using namespace std;


void Home::leader_board()
{

    vector<pair<qint64, QString>> v;
    int admins = 0;
    for(auto it = d_users.begin(); it != d_users.end(); it++){
        if(!it->second.is_admin)
            v.push_back(make_pair(it->second.points, it->second.username));
        else
            admins++;
    }
    sort(v.rbegin(),v.rend());
    int rowNum = 0;
    ui->tw_leader_board->setRowCount(users::size-admins);
    for(auto i = v.begin() ; i != v.end() ; i++, rowNum++)
    {
        switch (rowNum) {
        case 0:
        {
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setData(Qt::DecorationRole,QPixmap(":/Icons/1.png").scaled(50,50,Qt::IgnoreAspectRatio));
            ui->tw_leader_board->setItem(0,0,item);
            break;
        }
        case 1:
        {
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setData(Qt::DecorationRole,QPixmap(":/Icons/2.png").scaled(60,60,Qt::IgnoreAspectRatio));
            ui->tw_leader_board->setItem(1,0,item);
            break;
        }
        case 2:
        {
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setData(Qt::DecorationRole,QPixmap(":/Icons/3.png").scaled(60,60,Qt::IgnoreAspectRatio));
            ui->tw_leader_board->setItem(2,0,item);
            break;
        }
        default:
            ui->tw_leader_board->setItem(rowNum,0,new QTableWidgetItem(QString::number(rowNum+1)));
            break;
        }

        ui->tw_leader_board->setItem(rowNum,1,new QTableWidgetItem(QString(i->second)));
        ui->tw_leader_board->setItem(rowNum,2,new QTableWidgetItem(QString::number(i->first)));
    }


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


    leader_board();

    ui->tabWidget->setTabVisible(4,d_users[current_user_id].is_admin);
    ui->tabWidget->setTabVisible(0,!d_users[current_user_id].is_admin);

    ui->gb_user_update->hide();
    // hide delete users
        ui->gb_user_delete->hide();
    // hide insert users
        ui->gb_user_insert->hide();
    // hide update users
        ui->gb_user_update->hide();


    // hide update for players
        ui->gb_update_players->hide();
    // hide delete for players
        ui->gb_delete_players->hide();
    // hide delete for players
        ui->gb_insert_players->hide();
    // set max range for points & age and price spin box for player (admin)
        ui->sp_update_points_players->setMaximum(1000);
        ui->sp_update_age_players->setMaximum(50);
        ui->sp_update_price_players->setMaximum(10000000);
        ui->sp_insert_age_players->setMaximum(50);
        ui->sp_insert_points_players->setMaximum(1000);
        ui->sp_insert_price_players->setMaximum(10000000);

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
    qint64 id = ui->le_enter_id->text().toInt();
    if(ui->le_enter_id->text().isEmpty())
        return;
    if(id == current_user_id)
    {
        QMessageBox::critical(this,"Faild","You Can NOT delete Yourself!!");
        return;
    }
    if(is_found(id,d_users))
    {
        QMessageBox::warning(this,"deleted",d_users[id].username+" has been deleted successfully!");
        d_users.erase(id);
        users::size--;
        on_pb_read_clicked();
        leader_board();
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
        leader_board();
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
    if(!is_found(id,d_users))
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
    QString username = ui->le_username_update->text(),email = ui->le_email_update->text(), password = ui->le_password_update->text();
    if(!is_found(id,d_users))
    {
        QMessageBox::critical(this,"Error","there is no user with this id..!");
            return;
    }
    if(!valed_user(this,username,email,password))
        return;
    d_users[id].username = username;
    d_users[id].email = email;
    d_users[id].password = password;
    d_users[id].budget = ui->sb_budget_update->value();
    d_users[id].points = ui->sb_points_update->value();
    d_users[id].club_id = ui->cb_club_update->currentIndex()+1;
    d_users[id].is_admin = ui->is_admin_update->isChecked();
    QMessageBox::information(this,"success","done!");
    on_pb_read_clicked();
    leader_board();
    if(d_users[current_user_id].is_admin == false)
        Home::close();
}



/************** PLAYERS ****************/


void Home::on_pb_read_players_clicked()
{
    ui->tw_players->setRowCount(players::size);

    int rowNum = 0;
    // id , name , age , price , position , points
    for(auto player = d_players.begin() ; player != d_players.end() ; player++ , rowNum++)
    {
        ui->tw_players->setItem(rowNum,0,new QTableWidgetItem(QString::number(player->first)));
        ui->tw_players->setItem(rowNum,1,new QTableWidgetItem(QString(player->second.name)));
        ui->tw_players->setItem(rowNum,2,new QTableWidgetItem(QString::number(player->second.age)));
        ui->tw_players->setItem(rowNum,3,new QTableWidgetItem(QString::number(player->second.price)));
        ui->tw_players->setItem(rowNum,4,new QTableWidgetItem(QString(player->second.position)));
        ui->tw_players->setItem(rowNum,5,new QTableWidgetItem(QString::number(player->second.points)));
        ui->tw_players->setItem(rowNum,6,new QTableWidgetItem(QString::number(player->second.club_id)));
    }
}

void Home::on_pb_update_players_clicked()
{
    if( !ui->gb_update_players->isVisible())
    {
        ui->gb_update_players->show();
    }
    else
        ui->gb_update_players->hide();
}



void Home::on_pb_update_target_players_clicked()
{
    qint64 id = ui->le_target_id_players->text().toInt();
    if(!is_found(id,d_players))
    {
        QMessageBox::critical(this,"Error","there is no player with this id..!");
        return;
    }
    ui->le_name_update_players->setText(d_players[id].name);
    ui->le_position_update_players->setText(d_players[id].position);
    ui->sp_update_price_players->setValue(d_players[id].price);
    ui->sp_update_age_players->setValue(d_players[id].age);
    ui->sp_update_points_players->setValue(d_players[id].points);
    ui->cb_club_update_players->setCurrentIndex(d_players[id].club_id-1);
    ui->is_admin_update->setChecked(d_users[id].is_admin);
}

void Home::on_pb_update_confirm_players_clicked()
{
    qint64 id = ui->le_target_id_players->text().toInt();
    if(!is_found(id,d_players))
    {
        QMessageBox::critical(this,"Error","there is no user with this id..!");
        return;
    }
    d_players[id].name = ui->le_name_update_players->text();
    d_players[id].position = ui->le_position_update_players->text();
    d_players[id].age = ui->sp_update_age_players->value();
    d_players[id].price = ui->sp_update_price_players->value();
    d_players[id].points = ui->sp_update_points_players->value();
    d_players[id].club_id = ui->cb_club_update_players->currentIndex()+1;
    QMessageBox::information(this,"success","done!");
    on_pb_read_players_clicked();
}




void Home::on_pb_delete_players_clicked()
{
    if(!ui->gb_delete_players->isVisible())
        ui->gb_delete_players->show();
    else
        ui->gb_delete_players->hide();
}


void Home::on_pb_delete_confirm_players_clicked()
{
    qint64 id = ui->le_delete_id_players->text().toInt();
    if(ui->le_delete_id_players->text().isEmpty())
    {
        QMessageBox::critical(this,"Faild","Empty ID OR NOT VALID ID");
        return;
    }

    if(is_found(id,d_players))
    {
        QMessageBox::warning(this,"deleted",d_players[id].name+" has been deleted successfully!");
        d_players.erase(id);
        players::size--;
        on_pb_read_players_clicked();
    }
    else
        QMessageBox::critical(this,"Error","there is no user with this id..!");
}




void Home::on_pb_insert_players_clicked()
{
    if(!ui->gb_insert_players->isVisible())
        ui->gb_insert_players->show();
    else
        ui->gb_insert_players->hide();
}


void Home::on_pb_insert_confirm_players_clicked()
{
    bool checkAllInputNotEmpty = false;
    if(!ui->le_name_insert_players->text().isEmpty()
        && !ui->sp_insert_age_players->text().isEmpty()
        && !ui->le_position_insert_players->text().isEmpty()
        && !ui->sp_insert_points_players->text().isEmpty()
        && !ui->sp_insert_price_players->text().isEmpty()
        )
        checkAllInputNotEmpty = true;


    if(checkAllInputNotEmpty)
    {
        players::size++;
        d_players[++max_players_id].name = ui->le_name_insert_players->text();
        d_players[max_players_id].position = ui->le_position_insert_players->text();
        d_players[max_players_id].age = ui->sp_insert_age_players->value();
        d_players[max_players_id].points = ui->sp_insert_points_players->value();
        d_players[max_players_id].price = ui->sp_insert_price_players->value();
        d_players[max_players_id].club_id = (ui->cb_club_insert_players->currentIndex())+1;
        QMessageBox::information(this,"success","done!");
        on_pb_read_players_clicked();
    }
    else
        QMessageBox::critical(this,"Error","invaled data!");

}



