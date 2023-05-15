#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"signup.h"
#include"home.h"
#include <QMainWindow>
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
//#include<QDir>
#include<QFileInfo>
#include<QString>
//#include<QCoreApplication>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    SignUp signUpUi;
    Home *homeui;
};
#endif // MAINWINDOW_H
