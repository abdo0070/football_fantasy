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
    bool find_user(qint64 id);
    explicit Home(QWidget *parent = nullptr);
    ~Home();
    bool found_player(qint64 id);
private slots:

    void on_pb_user_update_clicked();

    void on_pb_conform_update_clicked();

    void on_pushButton_clicked();

    void on_pb_read_clicked();

    void on_pb_delete_clicked();

    void on_pb_conform_clicked();

    void on_pb_insert_clicked();

    void on_pb_conform_insert_clicked();

    void on_pb_update_clicked();

    void on_pb_update_players_clicked();

    void on_pb_update_target_players_clicked();

    void on_pb_update_confirm_players_clicked();

    void on_pb_read_players_clicked();

    void on_pb_delete_players_clicked();

    void on_pb_delete_confirm_players_clicked();

    void on_pb_insert_players_clicked();

    void on_pb_insert_confirm_players_clicked();

    void on_search_button_clicked();

    void on_player_clicked();

    void on_sellButton_clicked();

    void on_buyButton_clicked();

private:
    Ui::Home *ui;
};

#endif // HOME_H
