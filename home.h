#ifndef HOME_H
#define HOME_H

#include <QDialog>

namespace Ui {
class Home;
}

class Home : public QDialog
{
    Q_OBJECT

public:


    void leader_board();
    void refresh_players();
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

    QString on_pb_insert_logo_clubs_clicked();

    QString on_pb_shirt_insert_clubs_clicked();

    void on_pb_insert_confirm_clubs_clicked();

    void on_pb_read_clubs_clicked();

    void on_pb_delete_confirm_clubs_clicked();

private:
    Ui::Home *ui;
};

#endif // HOME_H
