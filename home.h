#ifndef HOME_H
#define HOME_H

#include <QDialog>
#include<QListWidgetItem>
namespace Ui {
class Home;
}

class Home : public QDialog
{
    Q_OBJECT

public:
    void player_squad(QString pushed_player_name_out_squad,QPushButton  * button , QLabel * label , qint64 num_of_pos, QString pos1, QString pos2 = "", QString pos3 = "");
    void refresh_squad();
    void profile();
    void clear_squad(qint64 user_team_id);
    void leader_board();
    void refresh_players();
    void refresh_clubs_comboboxs();
    void refresh_matches();
    QString shirt_image_file();
    QString club_image_file();

    //void vs_club1(qint64 club_id);
    void vs_club2(qint64 club_id);

    explicit Home(QWidget *parent = nullptr);
    ~Home();

private slots:
    //************ Admin users ******************//

    void on_pushButton_clicked();

    void on_pb_read_clicked();

    void on_pb_delete_clicked();

    void on_pb_conform_clicked();

    void on_pb_insert_clicked();

    void on_pb_conform_insert_clicked();

    void on_pb_update_clicked();

    void on_pb_conform_update_clicked();

    void on_pb_user_update_clicked();

    //************ Admin players ******************//

    void on_pb_update_players_clicked();

    void on_pb_update_target_players_clicked();

    void on_pb_update_confirm_players_clicked();

    void on_pb_read_players_clicked();

    void on_pb_delete_players_clicked();

    void on_pb_delete_confirm_players_clicked();

    void on_pb_insert_players_clicked();

    void on_pb_insert_confirm_players_clicked();

    //**************** market ***************//
    void on_search_button_clicked();

    void on_player_profile_clicked();

    void on_sellButton_clicked();

    void on_buyButton_clicked();

    //**************** Admin matches ******************//
    void on_pb_declare_result_clicked();



    void on_cb_choose_club1_currentIndexChanged();
    void on_cb_choose_club2_currentIndexChanged();

    void on_pb_matches_delete_player_club1_clicked();

    void on_pb_matches_delete_player_club2_clicked();

 //**************** Admin clubs ******************//

    void on_pb_insert_logo_clubs_clicked();

    void on_pb_shirt_insert_clubs_clicked();

    void on_pb_insert_confirm_clubs_clicked();

    void on_pb_read_clubs_clicked();

    void on_pb_delete_confirm_clubs_clicked();

    void on_pb_update_clubs_clicked();

    void on_pb_delete_clubs_clicked();

    void on_pb_insert_clubs_clicked();

    void on_pb_update_confirm_clubs_clicked();

    void on_pb_update_logo_clubs_clicked();

    void on_pb_shirt_update_clubs_clicked();

    void on_pb_update_refresh_clubs_clicked();

//**************** Profile ******************//

    void on_clearButton_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_LW_button_clicked();

    void on_CB1_button_clicked();

    void on_CB2_button_clicked();

    void on_RB_button_clicked();

    void on_CB3_button_clicked();

    void on_CM2_button_clicked();

    void on_CM1_button_clicked();

    void on_CM3_button_clicked();

    void on_GK1_button_clicked();

    void on_GK2_button_clicked();

    void on_LB_button_clicked();

    void on_LM_button_clicked();

    void on_RM_button_clicked();

    void on_RW_button_clicked();

    void on_ST_button_clicked();

private:
    Ui::Home *ui;
};

#endif // HOME_H
