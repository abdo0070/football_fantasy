#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    int checked;
    void refresh();
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pb_LaLiga_clicked();

    void on_pb_Premier_League_clicked();

    void on_pb_Egyptian_League_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
