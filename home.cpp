#include "home.h"
#include "ui_home.h"
#include <QPixmap>
#include"data.h"
#include<iostream>
#include<QPushButton>
#include<QMessageBox>
#include <queue>
#include"SUPPORT.cpp"
#include <QFileDialog>
#include <qdebug.h>
#include<QTableWidgetItem>
#include<QException>
#include<QtExceptionHandling>
#include<QItemDelegate>
#include<QLabel>
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

void Home::refresh_players()
{
    queue<pair<QString,QPixmap>> my_players;
    for(auto i = d_teams_players.begin() ; i != d_teams_players.end() ; i++)
    {
        if(d_teams[i->second.team_id].user_id == current_user_id)
            my_players.push(make_pair(d_players[i->second.player_id].name,QPixmap(d_clubs[d_players[i->second.player_id].club_id].shirt_image)));
    }

    if(!my_players.empty())
    {
        ui->PLAYER_NAME->setText(my_players.front().first);
        ui->PLAYER_IMAGE->setPixmap(my_players.front().second);
        my_players.pop();
    }
    else {
        ui->PLAYER_NAME->clear();
        ui->PLAYER_IMAGE->clear();
    }
    if(!my_players.empty())
    {
        ui->PLAYER_NAME_2->setText(my_players.front().first);
        ui->PLAYER_IMAGE_2->setPixmap(my_players.front().second);
        my_players.pop();
    }
    else {
        ui->PLAYER_NAME_2->clear();
        ui->PLAYER_IMAGE_2->clear();
    }
    if(!my_players.empty())
    {
        ui->PLAYER_NAME_3->setText(my_players.front().first);
        ui->PLAYER_IMAGE_3->setPixmap(my_players.front().second);
        my_players.pop();
    }
    else {
        ui->PLAYER_NAME_3->clear();
        ui->PLAYER_IMAGE_3->clear();
    }
    if(!my_players.empty())
    {
        ui->PLAYER_NAME_4->setText(my_players.front().first);
        ui->PLAYER_IMAGE_4->setPixmap(my_players.front().second);
        my_players.pop();
    }
    else {
        ui->PLAYER_NAME_4->clear();
        ui->PLAYER_IMAGE_4->clear();
    }
    if(!my_players.empty())
    {
        ui->PLAYER_NAME_5->setText(my_players.front().first);
        ui->PLAYER_IMAGE_5->setPixmap(my_players.front().second);
        my_players.pop();
    }
    else {
        ui->PLAYER_NAME_5->clear();
        ui->PLAYER_IMAGE_5->clear();
    }
    if(!my_players.empty())
    {
        ui->PLAYER_NAME_6->setText(my_players.front().first);
        ui->PLAYER_IMAGE_6->setPixmap(my_players.front().second);
        my_players.pop();
    }
    else {
        ui->PLAYER_NAME_6->clear();
        ui->PLAYER_IMAGE_6->clear();
    }
    if(!my_players.empty())
    {
        ui->PLAYER_NAME_7->setText(my_players.front().first);
        ui->PLAYER_IMAGE_7->setPixmap(my_players.front().second);
        my_players.pop();
    }
    else {
        ui->PLAYER_NAME_7->clear();
        ui->PLAYER_IMAGE_7->clear();
    }
    if(!my_players.empty())
    {
        ui->PLAYER_NAME_8->setText(my_players.front().first);
        ui->PLAYER_IMAGE_8->setPixmap(my_players.front().second);
        my_players.pop();
    }
    else {
        ui->PLAYER_NAME_8->clear();
        ui->PLAYER_IMAGE_8->clear();
    }
    if(!my_players.empty())
    {
        ui->PLAYER_NAME_9->setText(my_players.front().first);
        ui->PLAYER_IMAGE_9->setPixmap(my_players.front().second);
        my_players.pop();
    }
    else {
        ui->PLAYER_NAME_9->clear();
        ui->PLAYER_IMAGE_9->clear();
    }
    if(!my_players.empty())
    {
        ui->PLAYER_NAME_10->setText(my_players.front().first);
        ui->PLAYER_IMAGE_10->setPixmap(my_players.front().second);
        my_players.pop();
    }
    else {
        ui->PLAYER_NAME_10->clear();
        ui->PLAYER_IMAGE_10->clear();
    }
    if(!my_players.empty())
    {
        ui->PLAYER_NAME_11->setText(my_players.front().first);
        ui->PLAYER_IMAGE_11->setPixmap(my_players.front().second);
        my_players.pop();
    }
    else {
        ui->PLAYER_NAME_11->clear();
        ui->PLAYER_IMAGE_11->clear();
    }
    if(!my_players.empty())
    {
        ui->PLAYER_NAME_12->setText(my_players.front().first);
        ui->PLAYER_IMAGE_12->setPixmap(my_players.front().second);
        my_players.pop();
    }
    else {
        ui->PLAYER_NAME_12->clear();
        ui->PLAYER_IMAGE_12->clear();
    }
    if(!my_players.empty())
    {
        ui->PLAYER_NAME_13->setText(my_players.front().first);
        ui->PLAYER_IMAGE_13->setPixmap(my_players.front().second);
        my_players.pop();
    }
    else {
        ui->PLAYER_NAME_13->clear();
        ui->PLAYER_IMAGE_13->clear();
    }
    if(!my_players.empty())
    {
        ui->PLAYER_NAME_14->setText(my_players.front().first);
        ui->PLAYER_IMAGE_14->setPixmap(my_players.front().second);
        my_players.pop();
    }
    else {
        ui->PLAYER_NAME_14->clear();
        ui->PLAYER_IMAGE_14->clear();
    }
    if(!my_players.empty())
    {
        ui->PLAYER_NAME_15->setText(my_players.front().first);
        ui->PLAYER_IMAGE_15->setPixmap(my_players.front().second);
        my_players.pop();
    }
    else {
        ui->PLAYER_NAME_15->clear();
        ui->PLAYER_IMAGE_15->clear();
    }
}

class Delegate : public QItemDelegate
{
public:
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem & option, const QModelIndex & index) const
    {
        QLineEdit *lineEdit = new QLineEdit(parent);
        // Set validator
        QIntValidator *validator = new QIntValidator(-10000000,10000000, lineEdit);
        lineEdit->setValidator(validator);
        return lineEdit;
    }
};

void Home::refresh_matches()
{
    bool Premier = false;
    bool Egyptian = false;
    bool LaLiga = false;

    for(auto i = d_matches.begin() ; i != d_matches.end() ; i++)
    {
        if(d_leagues[d_clubs[i->second.club_1].league_id].name == "Premier League")// Premier League
        {
            Premier = true;
            ui->club1_on_premier_league->setPixmap(QPixmap(d_clubs[i->second.club_1].club_image));
            ui->club2_on_premier_league->setPixmap(QPixmap(d_clubs[i->second.club_2].club_image));
            ui->l_premier_league_result_club1->setText(QString::number(i->second.result_of_club1));
            ui->l_premier_league_result_club2->setText(QString::number(i->second.result_of_club2));

            // row count calculating
            qint64 size = 0;
            for(auto j = d_matches_players.begin() ; j != d_matches_players.end() ; j++)
                if(j->second.match_id == i->first)
                    size++;

            ui->tw_premier_league_results->setRowCount(size);
            qint64 rowNum = 0;
            for(auto j = d_matches_players.begin() ; j != d_matches_players.end() ; j++)
            {
                if(j->second.match_id == i->first)
                {
                    ui->tw_premier_league_results->setItem(rowNum,0,new QTableWidgetItem(QString(d_players[j->second.player_id].name)));
                    qint64 new_points = j->second.points;
                    ui->tw_premier_league_results->setItem(rowNum,1,new QTableWidgetItem(QString::number(new_points)));
                    rowNum++;
                }
            }
        }
        else if(d_leagues[d_clubs[i->second.club_1].league_id].name == "Egyption League")// Egyption League
        {
            Egyptian = true;
            ui->club1_on_egyptian_league->setPixmap(QPixmap(d_clubs[i->second.club_1].club_image));
            ui->club2_on_egyptian_league->setPixmap(QPixmap(d_clubs[i->second.club_2].club_image));
            ui->l_egyptian_league_result_club1->setText(QString::number(i->second.result_of_club1));
            ui->l_egyptian_league_result_club2->setText(QString::number(i->second.result_of_club2));

            // row count calculating
            qint64 size = 0;
            for(auto j = d_matches_players.begin() ; j != d_matches_players.end() ; j++)
                if(j->second.match_id == i->first)
                    size++;

            ui->tw_egyptian_league_results->setRowCount(size);
            qint64 rowNum = 0;
            for(auto j = d_matches_players.begin() ; j != d_matches_players.end() ; j++)
            {
                if(j->second.match_id == i->first)
                {
                    ui->tw_egyptian_league_results->setItem(rowNum,0,new QTableWidgetItem(QString(d_players[j->second.player_id].name)));
                    qint64 new_points = j->second.points;
                    ui->tw_egyptian_league_results->setItem(rowNum,1,new QTableWidgetItem(QString::number(new_points)));
                    rowNum++;
                }
            }
        }
        else // Laliga
        {
            LaLiga = true;
            ui->club1_on_LaLiga->setPixmap(QPixmap(d_clubs[i->second.club_1].club_image));
            ui->club2_on_LaLiga->setPixmap(QPixmap(d_clubs[i->second.club_2].club_image));
            ui->l_LaLiga_result_club1->setText(QString::number(i->second.result_of_club1));
            ui->l_LaLiga_result_club2->setText(QString::number(i->second.result_of_club2));

            // row count calculating
            qint64 size = 0;
            for(auto j = d_matches_players.begin() ; j != d_matches_players.end() ; j++)
                if(j->second.match_id == i->first)
                    size++;

            ui->tw_LaLiga_results->setRowCount(size);
            qint64 rowNum = 0;
            for(auto j = d_matches_players.begin() ; j != d_matches_players.end() ; j++)
            {
                if(j->second.match_id == i->first)
                {
                    ui->tw_LaLiga_results->setItem(rowNum,0,new QTableWidgetItem(QString(d_players[j->second.player_id].name)));
                    qint64 new_points = j->second.points;
                    ui->tw_LaLiga_results->setItem(rowNum,1,new QTableWidgetItem(QString::number(new_points)));
                    rowNum++;
                }
            }
        }
    }
    if(Premier)
        ui->gb_matches_premier_league->show();
    else
        ui->gb_matches_premier_league->hide();
    if(Egyptian)
        ui->gb_egyptian_league->show();
    else
        ui->gb_egyptian_league->hide();
    if(LaLiga)
        ui->gb_matches_LaLiga->show();
    else
        ui->gb_matches_LaLiga->hide();
}

Home::Home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    QPixmap pic(d_clubs[d_users[current_user_id].club_id].club_image);

    ui->profile_picture->setPixmap(pic);

    ui->tw_matches_club1->setItemDelegate(new Delegate);
    ui->tw_matches_club2->setItemDelegate(new Delegate);

    //matches();
    profile();
    refresh_squad();
    leader_board();
    refresh_players();
    refresh_clubs_comboboxs();
    refresh_matches();
    vs_club2(1);


    ui->tabWidget->setTabVisible(5,d_users[current_user_id].is_admin); // first parameter is the index of the tab
    ui->tabWidget->setTabVisible(0,!d_users[current_user_id].is_admin);

    ui->l_market_budget->setText("Your Budget : " + QString::number(d_users[current_user_id].budget)+'$');

    ui->gb_user_update->hide();
    // hide delete users
        ui->gb_user_delete->hide();
    // hide update users
        ui->gb_user_update->hide();
    // hide insert users
    ui->gb_user_insert->hide();

    // hide update for players
        ui->gb_update_players->hide();
    // hide delete for players
        ui->gb_delete_players->hide();
    // hide insert for players
        ui->gb_insert_players->hide();

    // hide update for clubs
    ui->gb_update_clubs->hide();
    // hide delete for clubs
    ui->gb_delete_clubs->hide();
    // hide insert for clubs
    ui->gb_insert_clubs->hide();

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

/************** Admin USERS ****************/

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
        users::remove(id);
        // refresh
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
    QString username = ui->le_username_insert->text();
    QString email = ui->le_email_insert->text();
    QString password = ui->le_password_insert->text();

    if(valed_user(this,username,email,password) && !is_repeated(this,username,email))
    {
        users::size++;
        d_teams[++max_teams_id].user_id = ++max_users_id;
        d_users[max_users_id].username = username;
        d_users[max_users_id].email = email;
        d_users[max_users_id].password = password;
        d_users[max_users_id].budget = ui->sb_budget_insert->text().toInt();
        d_users[max_users_id].points = ui->sb_points_insert->text().toInt();
        d_users[max_users_id].is_admin = ui->is_admin_insert->isChecked();
        d_users[max_users_id].number_of_players = 0;
        d_users[max_users_id].club_id = (ui->cb_club_insert->currentIndex())+1;
        QMessageBox::information(this,"success","done!");

        // refresh
        on_pb_read_clicked();
        leader_board();
    }
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
    QString username = ui->le_username_update->text();
    QString email = ui->le_email_update->text();
    QString password = ui->le_password_update->text();
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

    // refresh
    on_pb_read_clicked();
    leader_board();
    if(d_users[current_user_id].is_admin == false)
        Home::close();
}


/************** Admin PLAYERS ****************/

bool hold_currentIndexChanged = false;
void Home::refresh_clubs_comboboxs()
{
    hold_currentIndexChanged = true;

    ui->cb_club_update_players->clear();
    ui->cb_club_insert_players->clear();
    ui->cb_club_update->clear();
    ui->cb_club_insert->clear();
    ui->cb_choose_club1->clear();
    ui->cb_choose_club2->clear();


    for(auto i = d_clubs.begin() ; i != d_clubs.end() ; i++)
    {
        ui->cb_club_update_players->addItem(i->second.name);
        ui->cb_club_insert_players->addItem(i->second.name);
        ui->cb_club_update->addItem(i->second.name);
        ui->cb_club_insert->addItem(i->second.name);
        ui->cb_choose_club1->addItem(i->second.name);
        ui->cb_choose_club2->addItem(i->second.name);
    }

    for(auto i = d_clubs.begin() ; i != d_clubs.end() ; i++)
    {
        if(i->second.name == ui->cb_choose_club1->currentText())
            ui->chosen_club1->setPixmap(QPixmap(i->second.club_image));
        if(i->second.name == ui->cb_choose_club2->currentText())
            ui->chosen_club2->setPixmap(QPixmap(i->second.club_image));
    }
    hold_currentIndexChanged = false;
}

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
    ui->cb_position_update_players->setCurrentIndex(ui->cb_position_update_players->findText(d_players[id].position));
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
    d_players[id].position = ui->cb_position_update_players->currentText();
    d_players[id].age = ui->sp_update_age_players->value();
    d_players[id].price = ui->sp_update_price_players->value();
    d_players[id].points = ui->sp_update_points_players->value();
    d_players[id].club_id = ui->cb_club_update_players->currentIndex()+1;
    QMessageBox::information(this,"success","done!");
    // refresh
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
        players::remove(id);
        // refresh
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
        && !ui->sp_insert_points_players->text().isEmpty()
        && !ui->sp_insert_price_players->text().isEmpty()
        )
        checkAllInputNotEmpty = true;

    if(checkAllInputNotEmpty)
    {
        players::size++;
        d_players[++max_players_id].name = ui->le_name_insert_players->text();
        d_players[max_players_id].position = ui->cb_position_insert_players->currentText();
        d_players[max_players_id].age = ui->sp_insert_age_players->value();
        d_players[max_players_id].points = ui->sp_insert_points_players->value();
        d_players[max_players_id].price = ui->sp_insert_price_players->value();
        qint64 new_club_id;
        for(auto i = d_clubs.begin(); i != d_clubs.end() ; i++)
        {
            if(ui->cb_club_insert_players->currentText() == i->second.name)
                new_club_id = i->first;
        }
        d_players[max_players_id].club_id = new_club_id;
        QMessageBox::information(this,"success","done!");
        // refresh
        on_pb_read_players_clicked();
    }
    else
        QMessageBox::critical(this,"Error","invaled data!");
}


/************** market PLAYERS ****************/

QPushButton* label;

void Home::on_search_button_clicked()
{
    if(ui->search_bar->text().isEmpty())
        return;

    QGridLayout *lay =new QGridLayout(this);
    QString s = ui->search_bar->text().toLower();
    vector<pair<double,int>> matches;

    for(auto i = d_players.begin() ; i != d_players.end() ; i++)
    {
        QString name = i->second.name.toLower();
        int match = 0;
        int bestmatch = 0;
        queue<int> indices;
        for(int k = 0; k < name.length(); k++)
        {
            if(name[k] == s[0] && k + s.size() < name.length())
                indices.push(k);
        }
        while(!indices.empty())
        {
            for (int j=indices.front();j<indices.front()+s.size();j++)
            {
                if(name[j] == s[j-indices.front()])
                    match++;
            }
            if(match > bestmatch)
                bestmatch = match;
            indices.pop();
        }
        if(bestmatch >= s.length()*0.6)
        {
            matches.push_back(make_pair(bestmatch/s.length(),i->first));
            //qDebug() << matches.back().first << " " << matches.back().second;
        }
    }
    sort(matches.rbegin(), matches.rend());
    for(int i = 0; i < int(matches.size()); i++)
    {
        players player = d_players[matches[i].second];
        if(ui->scrollContents->layout() != NULL)
        {
            QLayoutItem* item;
            while ((item = ui->scrollContents->layout()->takeAt(0)) != NULL)
            {
                delete item->widget();
                delete item;
            }
            delete ui->scrollContents->layout();
        }
        label = new QPushButton(player.name);
        label->setObjectName(player.name);
//        QLabel* lab =new QLabel(
//            "Age: "+ QString::number( player.age) +
//            "   position: " + player.position +
//            "   club:" + d_clubs[player.club_id].name +
//            "   price:" + QString::number( player.price));
        lay->addWidget(label);
       // lay->addWidget(lab);


        connect(label, SIGNAL(clicked()), this, SLOT(on_player_profile_clicked()));
    }

    ui->scrollContents->setLayout(lay);
    ui->scrollContents->setVisible(true);
    ui->scrollContents->show();

    ui->player_profile->hide();
}

QString buttonText;
QPushButton *player_name_button;
qint64 player_id;
bool inMyTeam = false;
void Home::on_player_profile_clicked()
{
   ui->scrollArea->setGeometry(75,150,1000,750);
   ui->player_profile->show();
   ui->image->setStyleSheet(""); // to filter white background
   //initializing the previously created button...
   player_name_button = new QPushButton;

   //recieving the button (name) clicked and assigning it to the pButton[x]...
   player_name_button = qobject_cast<QPushButton*>(sender());

   //assigning the text of the button to the string "buttonText"..
   buttonText = player_name_button->text();

   // recognize buttonText here
   ui->player_name->setText(buttonText);
   ui->player_name->setStyleSheet("font-family:century gothic;background:transparent;font-size:25px;color:yellow;Text-align:center");
   QString name;

   for(auto i = d_players.begin() ; i != d_players.end() ; i++)
   {
        name = i->second.name;
        if (buttonText == name)
        {
            player_id = i->first;
            auto club = d_clubs[i->second.club_id];
            ui->player_club->setText(club.name);
            ui->player_position->setText(i->second.position);
            QPixmap pix(d_clubs[i->second.club_id].shirt_image);
            ui->image->setScaledContents(1);
            ui->image->setPixmap(pix);
            break;
        }
   }
   ui->player_points->setText(QString::number(d_players[player_id].points));
   ui->player_price->setText(QString::number(d_players[player_id].price)+'$');

   inMyTeam = false;
   for(auto i = d_teams_players.begin() ; i != d_teams_players.end() ; i++)
   {
        if (i->second.player_id == player_id && d_teams[i->second.team_id].user_id == current_user_id)
        {
            inMyTeam = true;
            break;
        }
   }
   if (inMyTeam)
   {
        ui->buyButton->setEnabled(false);
        ui->sellButton->setEnabled(true);
   }
   else
   {
        ui->sellButton->setEnabled(false);
        ui->buyButton->setEnabled(true);
   }
   //qDebug() << "on_player_clicked is good";
}

void Home::on_sellButton_clicked()
{
    qint64 playerid_in_teamsplayers = 0;
    auto user = d_users.begin() ;
    for(; user != d_users.end() ; user++)
    {
        if (user->first == current_user_id)
        {
            //qDebug() << "The current user name is: " << user->second.username << "and has: " << user->second.budget;
            break;
        }
    }

    for(auto player = d_teams_players.begin(); player != d_teams_players.end(); player++)
    {
        if (player->second.player_id == player_id && d_teams[player->second.team_id].user_id == current_user_id)
        {
            playerid_in_teamsplayers = player->first;
            break;
        }
    }

   players player = d_players[player_id];
   QMessageBox::information(this,"Success","You sold this player successfully");
   d_users[current_user_id].number_of_players--;
   d_teams_players.erase(playerid_in_teamsplayers);


   ui->sellButton->setEnabled(false);
   ui->buyButton->setEnabled(true);

   user->second.budget += player.price;
   ui->l_market_budget->setText("Your Budget : " + QString::number(d_users[current_user_id].budget)+'$');


   refresh_players();
   profile();
   //qDebug() << "on_sellButton_clicked is good and the budget is: " << user->second.budget << "because player name is: " << player.name << "and his price is: " << player.price;
   refresh_squad();
}

void Home::on_buyButton_clicked()
{
    if(d_users[current_user_id].number_of_players == 15)
    {
        QMessageBox::critical(this,"Faild","your team is already full!");
        return;
    }
    users user = d_users[current_user_id];

    qint64 team_id = 0;
    players player = d_players[player_id];
    for(auto i = d_teams.begin() ; i != d_teams.end() ; i++)
    {
        if (i->second.user_id == current_user_id)
        {
            team_id = i->first;
            break;
        }
    }
    if (user.budget >= player.price)
    {
        QMessageBox::information(this,"Success","You bought this player successfully");
        d_teams_players[++max_teams_players_id].player_id = player_id;
        d_teams_players[max_teams_players_id].team_id = team_id;
        d_teams_players[max_teams_players_id].position = 0;
        d_users[current_user_id].number_of_players++;

        ui->buyButton->setEnabled(false);
        ui->sellButton->setEnabled(true);

        d_users[current_user_id].budget -= player.price;
        ui->l_market_budget->setText("Your Budget : " + QString::number(d_users[current_user_id].budget)+'$');
        profile();
        refresh_squad();
        refresh_players();
    }


}


/********************** Admin matches **********************/

qint64 club1 = 0;
qint64 club2 = 0;


void Home::vs_club2(qint64 club_id)
{
    hold_currentIndexChanged = true;
    ui->cb_choose_club2->clear();
    ui->chosen_club2->clear();

    for(auto i = d_clubs.begin() ; i != d_clubs.end() ; i++)
        if(i->second.league_id == d_clubs[club_id].league_id && club_id != i->first)
            ui->cb_choose_club2->addItem(i->second.name);

    QString club = ui->cb_choose_club2->currentText();


    club2 = clubs::find_id(club);


    QPixmap pix = d_clubs[club2].club_image;
    ui->chosen_club2->setPixmap(pix);

    hold_currentIndexChanged = false;

}
void Home::on_cb_choose_club1_currentIndexChanged()
{
    if(hold_currentIndexChanged)return;
    QString club = ui->cb_choose_club1->currentText();

    club1 = clubs::find_id(club);

    QPixmap pix = d_clubs[club1].club_image;
    ui->chosen_club1->setPixmap(pix);
    ui->tw_matches_club1->show();
    vs_club2(club1);

}
void Home::on_cb_choose_club2_currentIndexChanged()
{
    if(hold_currentIndexChanged)return;
    QString club = ui->cb_choose_club2->currentText();

    club2 = clubs::find_id(club);

    QPixmap pix = d_clubs[club2].club_image;
    ui->chosen_club2->setPixmap(pix);
    ui->tw_matches_club2->show();

}

void Home::on_pb_matches_delete_player_club1_clicked()
{
    if(ui->tw_matches_club1->rowCount() > 0)
        ui->tw_matches_club1->setRowCount(ui->tw_matches_club1->rowCount() - 1);
}
void Home::on_pb_matches_delete_player_club2_clicked()
{
    if(ui->tw_matches_club2->rowCount() > 0)
        ui->tw_matches_club2->setRowCount(ui->tw_matches_club2->rowCount() - 1);
}


void Home::on_pb_declare_result_clicked()
{
    qint64 club1 = clubs::find_id(ui->cb_choose_club1->currentText());
    qint64 club2 = clubs::find_id(ui->cb_choose_club2->currentText());

    // this club has been declared
    for(auto i = d_matches.begin() ; i != d_matches.end() ; i++)
    {
        if(club1 == i->second.club_1  || club1 == i->second.club_2)
        {
            QMessageBox::critical(this,"Error",d_clubs[club1].name + "'s result has been declared already...!");
            return;
        }
        if(club2 == i->second.club_1  || club2 == i->second.club_2)
        {
            QMessageBox::critical(this,"Error",d_clubs[club2].name + "'s result has been declared already...!");
            return;
        }
    }

    // are these players exist in these clubs ?
    for(auto i = 0 ; i < ui->tw_matches_club1->rowCount() ; i++)
    {
        qint64 player_id = ui->tw_matches_club1->item(i,0)->text().toInt();
        qint64 calculated_points = ui->tw_matches_club1->item(i,1)->text().toInt();
        if(!is_found(player_id,d_players) || d_clubs[d_players[player_id].club_id].name != ui->cb_choose_club1->currentText())
        {
            QMessageBox::critical(this,"Error","in club : " + ui->cb_choose_club1->currentText() + "\nthere is no player with this id at the row " + QString::number(i+1));
            return;
        }
        if(calculated_points == 0)
        {
            QMessageBox::critical(this,"Error","in club : " + ui->cb_choose_club1->currentText() + "\nInvaled update of points or not affected at the row " + QString::number(i+1));
            return;
        }
    }
    // same for club 2
    for(auto i = 0 ; i < ui->tw_matches_club2->rowCount() ; i++)
    {
        qint64 player_id = ui->tw_matches_club2->item(i,0)->text().toInt();
        qint64 calculated_points = ui->tw_matches_club2->item(i,1)->text().toInt();
        if(!is_found(player_id,d_players) || d_clubs[d_players[player_id].club_id].name != ui->cb_choose_club2->currentText())
        {
            QMessageBox::critical(this,"Error","in club : " + ui->cb_choose_club2->currentText() + "\nthere is no player with this id at the row " + QString::number(i+1));
            return;
        }
        if(calculated_points == 0 || ui->tw_matches_club2->item(i,1)->text().isEmpty())
        {
            QMessageBox::critical(this,"Error","in club : " + ui->cb_choose_club2->currentText() + "\nInvaled update of points or not affected at the row " + QString::number(i+1));
            return;
        }
    }


    if(ui->le_weak->text().isEmpty())
    {
        QMessageBox::critical(this,"Error","You Forgot to define the weak..!");
        return;
    }

    qint64 round_id = 0;
    for(auto i = d_rounds.begin() ; i != d_rounds.end() ; i++)
    {
        if(i->second.weak == ui->le_weak->text())
            round_id = i->first;
    }
    if(!round_id) // is this a new round or ..?
    {
        QMessageBox::StandardButton option = QMessageBox::information(this,"New Round ??","are you sure you want to declare a new rounds records ?",QMessageBox::Yes,QMessageBox::No);
        if(option == QMessageBox::No)
            return;
        d_rounds.clear();
        d_matches.clear();
        d_matches_players.clear();

        max_rounds_id  = max_matches_id = max_matches_players_id = 0;
        rounds::size = matches::size = matches_players::size = 0;

        d_rounds[++max_rounds_id].weak = ui->le_weak->text();

    }

    // reset data for matches (New Match)
    d_matches[++max_matches_id].club_1 = club1;
    d_matches[max_matches_id].club_2 = club2;
    d_matches[max_matches_id].round_id = round_id;
    d_matches[max_matches_id].result_of_club1 = ui->club_1_result->text().toInt();
    d_matches[max_matches_id].result_of_club2 = ui->club_2_result->text().toInt();

    matches::size++;

    // calculating the rest of the data
    for(auto i = 0 ; i < ui->tw_matches_club1->rowCount() ; i++)
    {
        qint64 player_id = ui->tw_matches_club2->item(i,0)->text().toInt();
        qint64 calculated_points = ui->tw_matches_club2->item(i,1)->text().toInt();

        d_players[player_id].points += calculated_points;
        d_players[player_id].price += (calculated_points * 1000);

        if(d_players[player_id].price < 0)// negative points or budgets @@!
            d_players[player_id].price = 0;

        if(d_players[player_id].points < 0)
            d_players[player_id].points = 0;

        d_matches_players[++max_matches_players_id].round_id = round_id;
        d_matches_players[max_matches_players_id].match_id = max_matches_id;
        d_matches_players[max_matches_players_id].player_id = player_id;
        d_matches_players[max_matches_players_id].points = calculated_points;

        // calculating the new points of users
        for(auto i = d_teams_players.begin() ; i != d_teams_players.end() ; i++)
        {
            if(i->second.player_id == player_id)
            {
                auto user = &d_users[d_teams[i->second.team_id].user_id];
                user->points += calculated_points;
                if(user->points < 0)
                    user->points = 0;
            }
        }
        matches_players::size++;
        refresh_matches();
        profile();

    }
    // the same with club2
    for(auto i = 0 ; i < ui->tw_matches_club2->rowCount() ; i++)
    {
        qint64 player_id = ui->tw_matches_club2->item(i,0)->text().toInt();
        qint64 calculated_points = ui->tw_matches_club2->item(i,1)->text().toInt();

        d_players[player_id].points += calculated_points;
        d_players[player_id].price += (calculated_points * 1000);

        if(d_players[player_id].price < 0)// negative points or budgets @@!
            d_players[player_id].price = 0;

        if(d_players[player_id].points < 0)
            d_players[player_id].points = 0;

        d_matches_players[++max_matches_players_id].round_id = round_id;
        d_matches_players[max_matches_players_id].match_id = max_matches_id;
        d_matches_players[max_matches_players_id].player_id = player_id;
        d_matches_players[max_matches_players_id].points = calculated_points;

        // calculating the new points of users
        for(auto i = d_teams_players.begin() ; i != d_teams_players.end() ; i++)
        {
            if(i->second.player_id == player_id)
            {
                auto user = &d_users[d_teams[i->second.team_id].user_id];
                user->points += calculated_points;
                if(user->points < 0)
                    user->points = 0;
            }
        }
        matches_players::size++;
    }

    // refresh the G.U.I

    refresh_players();
    on_search_button_clicked();

    // market updated
    leader_board();
    profile();
    refresh_matches();
}
/************************* ADMIN CLUB *****************************/
QString Chosen_new_club = "",Chosen_new_shirt = "";
QString Chosen_update_club = "",Chosen_update_shirt = "";

void Home::on_pb_update_clubs_clicked()
{
    if(!ui->gb_update_clubs->isVisible())
        ui->gb_update_clubs->show();
    else
        ui->gb_update_clubs->hide();
}

void Home::on_pb_delete_clubs_clicked()
{
    if(!ui->gb_delete_clubs->isVisible())
        ui->gb_delete_clubs->show();
    else
        ui->gb_delete_clubs->hide();
}
void Home::on_pb_insert_clubs_clicked()
{
    if(!ui->gb_insert_clubs->isVisible())
        ui->gb_insert_clubs->show();
    else
        ui->gb_insert_clubs->hide();
}

QString Home::shirt_image_file()
{
    return QFileDialog::getOpenFileName(this,"Select Logo","C://","Image files (*.jpg *.gif *.png)");
}
QString Home::club_image_file()
{
    return QFileDialog::getOpenFileName(this,"Select T-shirt","C://","Image files (*.jpg *.gif *.png)");
}

void Home::on_pb_insert_logo_clubs_clicked()
{
    Chosen_new_club = club_image_file();
}
void Home::on_pb_shirt_insert_clubs_clicked()
{
    Chosen_new_shirt = shirt_image_file();
}

void Home::on_pb_update_logo_clubs_clicked()
{
    QString file = club_image_file();
    if(!file.isEmpty())
    {
        Chosen_update_club = file;
        ui->l_Chosen_update_logo->setPixmap(QPixmap(Chosen_update_club));
    }
}
void Home::on_pb_shirt_update_clubs_clicked()
{
    QString file = shirt_image_file();
    if(!file.isEmpty())
    {
        Chosen_update_shirt = file;
        ui->l_Chosen_update_shirt->setPixmap(QPixmap(Chosen_update_shirt));
    }
}

void Home::on_pb_insert_confirm_clubs_clicked()
{
    QString name = ui->le_name_insert_clubs->text();
    if(name.isEmpty())
    {
        QMessageBox::critical(this,"Error","invaled club name!");
        return;
    }
    if(Chosen_new_club.isEmpty())
    {
        QMessageBox::StandardButton conform = QMessageBox::information(this,"ready?","are you sure you want the default settings for club Logo ?",QMessageBox::Yes,QMessageBox::No);
        if(conform == QMessageBox::No)
            return;
        Chosen_new_club = ":/background/Clubs/Default_club.png";
    }
    if(Chosen_new_shirt.isEmpty())
    {
        QMessageBox::StandardButton conform = QMessageBox::information(this,"ready?","are you sure you want the default settings for shirt image ?",QMessageBox::Yes,QMessageBox::No);
        if(conform == QMessageBox::No)
            return;
        Chosen_new_shirt = ":/background/shirts/Default_shirt.png";
    }
    d_clubs[++max_clubs_id].shirt_image = Chosen_new_shirt;
    d_clubs[max_clubs_id].name = name;
    d_clubs[max_clubs_id].club_image = Chosen_new_club;
    d_clubs[max_clubs_id].league_id = (ui->cb_league_insert_clubs->currentIndex()) + 1;

    QMessageBox::information(this,"success","inserted succesfuly");
    clubs::size++;

    on_pb_read_clubs_clicked();
    refresh_clubs_comboboxs();
    refresh_squad();
    refresh_players();
    Chosen_new_shirt = Chosen_new_club = "";

}
void Home::on_pb_read_clubs_clicked()
{
    ui->tw_clubs->setRowCount(clubs::size);
    int rowNum = 0;
    for(auto club = d_clubs.begin() ; club != d_clubs.end() ; club++ , rowNum++)
    {
        ui->tw_clubs->setItem(rowNum,0,new QTableWidgetItem(QString::number(club->first)));
        ui->tw_clubs->setItem(rowNum,1,new QTableWidgetItem(QString(club->second.name)));
        ui->tw_clubs->setItem(rowNum,2,new QTableWidgetItem(QString::number(club->second.league_id)));
    }
}

void Home::on_pb_delete_confirm_clubs_clicked()
{
    if(clubs::size == 1)
    {
        QMessageBox::critical(this,"Error","there is only one club left !");
        return;
    }
    qint64 id = ui->le_delete_id_clubs->text().toInt();
    if(ui->le_delete_id_clubs->text().isEmpty())
    {
        QMessageBox::critical(this,"Faild","Empty ID OR NOT VALID ID");
        return;
    }
    if(is_found(id,d_clubs))
    {
        QMessageBox::warning(this,"deleted",d_clubs[id].name+" has been deleted successfully!");
        clubs::remove(id);
        // refresh players
        on_pb_read_clubs_clicked();
        on_pb_read_players_clicked();
        refresh_players();
        refresh_clubs_comboboxs();
        on_search_button_clicked();

        return;
    }
    QMessageBox::critical(this,"Error","there is no user with this id..!");
}

void Home::on_pb_update_refresh_clubs_clicked()
{
    qint64 id = ui->le_target_id_clubs->text().toInt();
    if(is_found(id,d_clubs))
    {
        ui->le_name_update_clubs->setText(d_clubs[id].name);
        Chosen_update_club = d_clubs[id].club_image;
        Chosen_update_shirt = d_clubs[id].shirt_image;
        ui->l_Chosen_update_logo->setPixmap(QPixmap(Chosen_update_club));
        ui->l_Chosen_update_shirt->setPixmap(QPixmap(Chosen_update_shirt));
        ui->cb_league_update_clubs->setCurrentIndex(d_clubs[id].league_id - 1);
    }
    else
        QMessageBox::warning(this,"Error","there is no club whit this id");
}

void Home::on_pb_update_confirm_clubs_clicked()
{

    qint64 id = ui->le_target_id_clubs->text().toInt();
    if(!is_found(id,d_clubs))
    {
        QMessageBox::critical(this,"Error","there is no club with this id");
        return;
    }
    if(ui->le_name_update_clubs->text().isEmpty())
        QMessageBox::warning(this,"Error","empty club name!");

    if(Chosen_update_club.isEmpty())
        Chosen_update_club = d_clubs[id].club_image;

    if(Chosen_update_shirt.isEmpty())
        Chosen_update_shirt = d_clubs[id].shirt_image;

    d_clubs[id].name = ui->le_name_update_clubs->text();
    d_clubs[id].club_image = Chosen_update_club;
    d_clubs[id].shirt_image = Chosen_update_shirt;

    Chosen_update_club = Chosen_update_shirt = "";
    ui->l_Chosen_update_logo->clear();
    ui->l_Chosen_update_shirt->clear();
}
/********************** Profile **********************/

QString pushed_player_name_out_squad;
qint64 check_num_players_in_squad = 0;

void Home::profile()
{

    QPixmap club_icon(d_clubs[d_users[current_user_id].club_id].club_image);
    ui->profile_picture->setPixmap(club_icon);
    ui->username->setText(d_users[current_user_id].username + "'s team");
    ui->user_budget->setText(QString::number(d_users[current_user_id].budget) + "$");
    ui->user_points->setText(QString::number(d_users[current_user_id].points));
}

void Home::refresh_squad()
{
    players player;
    qint64 user_team_id = 0;
    for(auto i = d_teams.begin() ; i != d_teams.end() ; i++)
    {
        if (i->second.user_id == current_user_id)
        {
            user_team_id = i->first;
            break;
        }
    }
    ui->listWidget->clear();


    QString default_shirt = "://background/shirts/none_player.png";

    ui->GK1_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->GK1_name->setText("");
    ui->GK2_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->GK2_name->setText("");
    ui->LB_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->LB_name->setText("");
    ui->CB1_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->CB1_name->setText("");
    ui->CB2_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->CB2_name->setText("");
    ui->CB3_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->CB3_name->setText("");
    ui->RB_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->RB_name->setText("");
    ui->LM_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->LM_name->setText("");
    ui->CM1_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->CM1_name->setText("");
    ui->CM2_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->CM2_name->setText("");
    ui->CM3_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->CM3_name->setText("");
    ui->RM_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->RM_name->setText("");
    ui->LW_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->LW_name->setText("");
    ui->ST_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->ST_name->setText("");
    ui->RW_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->RW_name->setText("");


    // show d_players[i->second.player_id].name in the scrollbar for 0's position and the others in the squad
    for (auto i = d_teams_players.begin(); i != d_teams_players.end(); i++)
    {
        if (i->second.team_id == user_team_id)
        {
            player = d_players[i->second.player_id];
            auto player_shirt = d_clubs[player.club_id].shirt_image;

            switch (i->second.position)
            {
            case 0: // out
                ui->listWidget->addItem(player.name);
                break;
            case 1: // GK1
                ui->GK1_button->setStyleSheet("image: url("+ player_shirt + ");background: none;border: none;");
                ui->GK1_name->setText(player.name);
                break;
            case 2: // GK2
                ui->GK2_button->setStyleSheet("image: url("+ player_shirt + ");background: none;border: none;");
                ui->GK2_name->setText(player.name);
                break;
            case 3: // LB
                ui->LB_button->setStyleSheet("image: url("+ player_shirt + ");background: none;border: none;");
                ui->LB_name->setText(player.name);
                break;
            case 4: // CB1
                ui->CB1_button->setStyleSheet("image: url("+ player_shirt + ");background: none;border: none;");
                ui->CB1_name->setText(player.name);
                break;
            case 5: // CB2
                ui->CB2_button->setStyleSheet("image: url("+ player_shirt + ");background: none;border: none;");
                ui->CB2_name->setText(player.name);
                break;
            case 6: // CB3
                ui->CB3_button->setStyleSheet("image: url("+ player_shirt + ");background: none;border: none;");
                ui->CB3_name->setText(player.name);
                break;
            case 7: // RB
                ui->RB_button->setStyleSheet("image: url("+ player_shirt + ");background: none;border: none;");
                ui->RB_name->setText(player.name);
                break;
            case 8: // LM
                ui->LM_button->setStyleSheet("image: url("+ player_shirt + ");background: none;border: none;");
                ui->LM_name->setText(player.name);
                break;
            case 9: // CM1
                ui->CM1_button->setStyleSheet("image: url("+ player_shirt + ");background: none;border: none;");
                ui->CM1_name->setText(player.name);
                break;
            case 10: // CM2
                ui->CM2_button->setStyleSheet("image: url("+ player_shirt + ");background: none;border: none;");
                ui->CM2_name->setText(player.name);
                break;
            case 11: // CM3
                ui->CM3_button->setStyleSheet("image: url("+ player_shirt + ");background: none;border: none;");
                ui->CM3_name->setText(player.name);
                break;
            case 12: // RM
                ui->RM_button->setStyleSheet("image: url("+ player_shirt + ");background: none;border: none;");
                ui->RM_name->setText(player.name);
                break;
            case 13: // LW
                ui->LW_button->setStyleSheet("image: url("+ player_shirt + ");background: none;border: none;");
                ui->LW_name->setText(player.name);
                break;
            case 14: // ST
                ui->ST_button->setStyleSheet("image: url("+ player_shirt + ");background: none;border: none;");
                ui->ST_name->setText(player.name);
                break;
            case 15: // RW
                ui->RW_button->setStyleSheet("image: url("+ player_shirt + ");background: none;border: none;");
                ui->RW_name->setText(player.name);
                break;
            }

        }
    }
}
void Home::clear_squad(qint64 user_team_id)
{
    //    default position in teams_players = 0
    for(auto i = d_teams_players.begin() ; i != d_teams_players.end() ; i++)
    {
        if (i->second.team_id == user_team_id)
        {
            i->second.position = 0;
        }
    }
    QString default_shirt = "://background/shirts/none_player.png";

    ui->GK1_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->GK1_name->setText("");
    ui->GK2_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->GK2_name->setText("");
    ui->LB_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->LB_name->setText("");
    ui->CB1_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->CB1_name->setText("");
    ui->CB2_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->CB2_name->setText("");
    ui->CB3_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->CB3_name->setText("");
    ui->RB_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->RB_name->setText("");
    ui->LM_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->LM_name->setText("");
    ui->CM1_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->CM1_name->setText("");
    ui->CM2_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->CM2_name->setText("");
    ui->CM3_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->CM3_name->setText("");
    ui->RM_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->RM_name->setText("");
    ui->LW_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->LW_name->setText("");
    ui->ST_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->ST_name->setText("");
    ui->RW_button->setStyleSheet("image: url("+ default_shirt + ");background: none;border: none;");
    ui->RW_name->setText("");
    check_num_players_in_squad = 0;
}

void Home::on_clearButton_clicked()
{
    qDebug() << "ui->listWidget->currentItem()->text()";
    cout << "ui->listWidget->currentItem()->text()";
    qint64 user_team_id = 0;
    for(auto i = d_teams.begin() ; i != d_teams.end() ; i++)
    {
        if (i->second.user_id == current_user_id)
        {
            user_team_id = i->first;
            break;
        }
    }
    clear_squad(user_team_id);
    refresh_squad();
}



bool player_is_clicked = false;
void Home::on_listWidget_itemClicked(QListWidgetItem *item)
{
    player_is_clicked = true;
    //    QMessageBox::information(this, item->text(),"You choosed " + item->text() + "\nSelect his position in the squad");
    pushed_player_name_out_squad = item->text();
}


void Home::player_squad(QString pushed_player_name_out_squad,QPushButton  * button , QLabel * label, qint64 num_of_pos,QString pos1,QString pos2, QString pos3)
{
    players player;
    qint64 team_id = teams::team_id_user(current_user_id);

    for (auto i = d_teams_players.begin(); i != d_teams_players.end(); i++)
    {
        if (d_players[i->second.player_id].name == pushed_player_name_out_squad && i->second.team_id == team_id)
        {
            player = d_players[i->second.player_id];
        }
    }

    if (player_is_clicked)
    {
        // not in his position
        if (player.position != pos1 && player.position != pos2 && player.position != pos3)
            QMessageBox::warning(this, player.name,player.name + " is a " + player.position +",\nnot a " + pos1);
        else
        {
            // iterate over the teams-players map to find the player with the matching name and team ID
            for (auto i = d_teams_players.begin(); i != d_teams_players.end(); i++)
            {
                qDebug() << "check_num_players_in_squad: " << check_num_players_in_squad;
                if (d_players[i->second.player_id].name == pushed_player_name_out_squad && i->second.team_id == team_id)
                {
                    player = d_players[i->second.player_id];

                    // make the current player in the squad out if there is one
                    if (label->text() != pos1) {
                        for (auto j = d_teams_players.begin(); j != d_teams_players.end(); j++)
                        {
                            if (d_players[j->second.player_id].name == label->text()) {
                                j->second.position = 0;
                            }
                        }
                        // add the player right now if replacing with anther player in the squad
                        // assign the selected player to the squad
                        i->second.position = num_of_pos;
                        auto player_shirt = d_clubs[player.club_id].shirt_image;
                        button->setStyleSheet("image: url("+ player_shirt + ");background: none;border: none;");
                        label->setText(pushed_player_name_out_squad);
                    }
                    else
                    {
                        if (check_num_players_in_squad >= 11)
                            QMessageBox::warning(this, "Maximum number of players","You cannot insert players in the squad more than 11 player");
                        else
                        {
                            // add the player right now if inserting a new player in the squad and no. players in the squad < 11
                            // assign the selected player to the squad
                            i->second.position = num_of_pos;
                            auto player_shirt = d_clubs[player.club_id].shirt_image;
                            button->setStyleSheet("image: url("+ player_shirt + ");background: none;border: none;");
                            label->setText(pushed_player_name_out_squad);
                            cout << "check_num_players_in_squad: " << check_num_players_in_squad;
                            check_num_players_in_squad++;

                        }

                    }

                    break;
                }
            }
            refresh_squad();
        }
    }
    player_is_clicked = false;
}
void Home::on_GK1_button_clicked()
{
    player_squad(pushed_player_name_out_squad,ui->GK1_button ,ui->GK1_name, 1,"GoalKeeper");
}
void Home::on_GK2_button_clicked()
{
    player_squad(pushed_player_name_out_squad,ui->GK2_button ,ui->GK2_name, 2,"GoalKeeper");
}
void Home::on_LB_button_clicked()
{
    player_squad(pushed_player_name_out_squad,ui->CB1_button ,ui->CB1_name, 3,"Left-Back");
}
void Home::on_CB1_button_clicked()
{
    player_squad(pushed_player_name_out_squad,ui->CB1_button ,ui->CB1_name, 4,"Centre-Back");
}
void Home::on_CB2_button_clicked()
{
    player_squad(pushed_player_name_out_squad,ui->CB2_button ,ui->CB2_name, 5,"Centre-Back");
}
void Home::on_CB3_button_clicked()
{
    player_squad(pushed_player_name_out_squad,ui->CB3_button ,ui->CB3_name, 6,"Centre-Back");
}
void Home::on_RB_button_clicked()
{
    player_squad(pushed_player_name_out_squad,ui->RB_button ,ui->RB_name, 7,"Right-Back");
}
void Home::on_LM_button_clicked()
{
    player_squad(pushed_player_name_out_squad,ui->LM_button ,ui->LM_name, 8,"Left Winger", "Central Midfield", "Attacking Midfield");
}
void Home::on_CM1_button_clicked()
{
    player_squad(pushed_player_name_out_squad,ui->CM1_button ,ui->CM1_name, 9,"Defensive Midfield", "Central Midfield", "Attacking Midfield");
}
void Home::on_CM2_button_clicked()
{
    player_squad(pushed_player_name_out_squad,ui->CM2_button ,ui->CM2_name, 10,"Defensive Midfield", "Central Midfield", "Attacking Midfield");
}
void Home::on_CM3_button_clicked()
{
    player_squad(pushed_player_name_out_squad,ui->CM3_button ,ui->CM3_name, 11,"Defensive Midfield", "Central Midfield", "Attacking Midfield");

}
void Home::on_RM_button_clicked()
{
    player_squad(pushed_player_name_out_squad,ui->RM_button ,ui->RM_name, 12,"Right Winger", "Central Midfield", "Attacking Midfield");
}
void Home::on_LW_button_clicked()
{
    player_squad(pushed_player_name_out_squad,ui->LW_button ,ui->LW_name, 13,"Left Winger");
}
void Home::on_ST_button_clicked()
{
    player_squad(pushed_player_name_out_squad,ui->ST_button ,ui->ST_name, 14,"Second Striker", "Centre-Forward");
}
void Home::on_RW_button_clicked()
{
    player_squad(pushed_player_name_out_squad,ui->RW_button ,ui->RW_name, 15,"Right Winger");
}

