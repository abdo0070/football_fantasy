#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include "dialog.h"
namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:

    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

private slots:
    void on_pushButton_clicked();
    void on_submitButton_clicked();



private:
    Ui::SignUp *ui;
    Dialog ch_club;
};

#endif // SIGNUP_H
