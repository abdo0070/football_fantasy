#include "home.h"
#include "ui_home.h"
#include <QPixmap>
#include"data.h"
#include<iostream>
#include<QMessageBox>
#include <queue>
#include"SUPPORT.cpp"
#include <QFileDialog>
#include <qdebug.h>
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

Home::Home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    QPixmap profile(d_clubs[d_users[current_user_id].club_id].club_image);

    ui->profile_picture->setPixmap(profile);


    //matches();
    leader_board();
    refresh_players();

    ui->tabWidget->setTabVisible(4,d_users[current_user_id].is_admin); // first parameter is the index of the tab
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
    qint64 playerid_in_teamsplayers;
    auto user = d_users.begin() ;
    for(; user != d_users.end() ; user++)
    {
        if (user->first == current_user_id)
        {
            //qDebug() << "The current user name is: " << user->second.username << "and has: " << user->second.budget;
            break;
        }
    }


    // users user = d_users[current_user_id];

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
   refresh_players();
   //qDebug() << "on_sellButton_clicked is good and the budget is: " << user->second.budget << "because player name is: " << player.name << "and his price is: " << player.price;
}

void Home::on_buyButton_clicked()
{
    if(d_users[current_user_id].number_of_players == 15)
    {
        QMessageBox::critical(this,"Faild","your team is already full!");
        return;
    }
    auto user = d_users.begin() ;
    for(; user != d_users.end() ; user++)
    {
        if (user->first == current_user_id)
        {
            //qDebug() << "The current user name is: " << user->second.username << "and has: " << user->second.budget;
            break;
        }
    }

    qint64 team_id;
    players player = d_players[player_id];
    for(auto i = d_teams.begin() ; i != d_teams.end() ; i++)
    {
        if (i->second.user_id == current_user_id)
        {
            team_id = i->first;
            break;
        }
    }
    if (user->second.budget >= player.price)
    {
        QMessageBox::information(this,"Success","You bought this player successfully");

        d_teams_players[++max_teams_players_id].player_id = player_id;
        d_teams_players[max_teams_players_id].team_id = team_id;
        d_users[current_user_id].number_of_players++;

        ui->buyButton->setEnabled(false);
        ui->sellButton->setEnabled(true);

        d_users[current_user_id].budget -= player.price;
        refresh_players();
    }
    // qDebug() << "on_buyButton_clicked is good and the budget is: " << user->second.budget << "because player name is: " << player.name << "and his price is: " << player.price;
    // qDebug() << "*********Mission is completed*********";
}

/********************** Admin matches **********************/

int club1 = 0;
int club2 = 0;
/************************* ADMIN CLUB *****************************/
QString Home::on_pb_insert_logo_clubs_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Select Logo","C://","Image files (*.jpg *.gif *.png)");
    return fileName;
}


QString Home::on_pb_shirt_insert_clubs_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Select T-shirt","C://","Image files (*.jpg *.gif *.png)");
    return fileName;
}


void Home::on_pb_insert_confirm_clubs_clicked()
{
    QString shirt = on_pb_shirt_insert_clubs_clicked();
    QString logo = on_pb_insert_logo_clubs_clicked();
    QString name = ui->le_name_insert_clubs->text();
    if(logo.isEmpty() || shirt.isEmpty() || name.isEmpty()){
        QMessageBox::information(this,"Error","select t-shirt and logo");
        return;
    }
    d_clubs[++max_clubs_id].shirt_image = shirt;
    d_clubs[max_clubs_id].name = name;
    d_clubs[max_clubs_id].club_image = logo;
    d_clubs[max_clubs_id].league_id = (ui->cb_league_insert_clubs->currentIndex())+1;
    QMessageBox::information(this,"success","inserted succesfuly");
    on_pb_read_clubs_clicked();
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
    qint64 id = ui->le_delete_id_clubs->text().toInt();
    if(ui->le_delete_id_clubs->text().isEmpty())
    {
        QMessageBox::critical(this,"Faild","Empty ID OR NOT VALID ID");
        return;
    }
    if(is_found(id,d_clubs))
    {
        QMessageBox::warning(this,"deleted",d_clubs[id].name+" has been deleted successfully!");
        // delete club
        clubs::remove(id);
        on_pb_read_clubs_clicked();
        return;
    }
    QMessageBox::critical(this,"Error","there is no user with this id..!");
}


