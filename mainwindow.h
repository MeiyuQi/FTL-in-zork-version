#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ZorkUL.h"
#include "timenow.h"
#include "ship.h"
#include <stdlib.h>
#include <QMessageBox>
#include <QScrollBar>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    ZorkUL temp;

    Ship *my_ship;
    bool is_start = false;
    void check_Item(string des);
    void start_attack(Ship *enemy);


private slots:
    void on_Infobt_clicked();

    void on_mapbt_clicked();

    void on_startbt_clicked();

    void on_northbt_clicked();

    void on_westbt_clicked();

    void on_southbt_clicked();

    void on_eastbt_clicked();

    void on_telebt_clicked();

    void on_quitbt_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
