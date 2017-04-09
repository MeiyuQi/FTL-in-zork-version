#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(is_start==false)
            ui->infote->append("please enter the name of your ship and click start");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Infobt_clicked()
{
    ui->infote->append("\ninfo:\nThere has nine rooms\nTo press Map, you'll see all the rooms\nOne of the rooms has the key\nOne of the rooms has the door\nYou have to find the key and open the door, then you will win\nBe carefully, you may meet enemy ship at some rooms.");
    ui->infote->verticalScrollBar()->setValue(ui->infote->verticalScrollBar()->maximum());

}

void MainWindow::on_mapbt_clicked()
{
    if(is_start==false)
            ui->infote->append("please enter the name of your ship and click start");
    else{
    ui->infote->append("\nmap:\n"
                           "[h] --- [f] --- [g]\n"
                           "         |         \n"
                           "         |         \n"
                           "[c] --- [a] --- [b]\n"
                           "         |         \n"
                           "         |         \n"
                           "[i] --- [d] --- [e]\n");
    ui->infote->verticalScrollBar()->setValue(ui->infote->verticalScrollBar()->maximum());

    }
}

void MainWindow::on_startbt_clicked()
{
    if(ui->namete->toPlainText().toStdString().compare("")!=0){

        //operator overloading
        Ship c("cccc");
        Ship d("dddd");
        Ship a = c+d;

        //virtual fun_c
        Character *my =new Ship(ui->namete->toPlainText().toStdString());
        //coercion
        my_ship = (Ship *)(my);

        is_start = true;
        QString des= QString::fromStdString(temp.currentRoom->longDescription());
        //virtual fun_c
        ui->infote->setText("start\ninfo for help\n"+des+"\nYour ship's name is "+QString::fromStdString(my->get_des()));
        ui->infote->append("operator overloading: "+QString::fromStdString(a.get_des()));

    }
    else
         ui->infote->append("please enter the name of your ship and click start");
}



void MainWindow::check_Item(string des){
    ui->infote->append("\n");
    if(is_start==false)
            ui->infote->append("please enter the name of your ship and click start");
    else{

    ui->infote->verticalScrollBar()->setValue(ui->infote->verticalScrollBar()->maximum());
    string my_name = my_ship->get_ship_name();
    int my_power = my_ship->getPower();
    if(des == "Kestrel")
    {
        Ship *enemyb = new Ship("Kestrel");

        string it_name = enemyb->get_ship_name();
        int it_power = enemyb->getPower();
//pro

        if(my_ship->test_temp(my_name,it_name) == my_name||my_ship->test_temp(my_power,it_power)==my_power){
            QMessageBox::StandardButton rb = QMessageBox::information(NULL, "Warn!", "You meet a horrible enemy, do you want to attack?", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            if(rb==QMessageBox::Yes){
                start_attack(enemyb);
            }
            else{
                ui->infote->append("R!U!N!");
                ui->infote->verticalScrollBar()->setValue(ui->infote->verticalScrollBar()->maximum());
            }


        }
        else
            start_attack(enemyb);

    }
    else if(des =="Engi"){
        Ship *enemyd = new Ship("Engi");
        string it_name = enemyd->get_ship_name();
        int it_power = enemyd->getPower();
        if(my_ship->test_temp(my_name,it_name) == my_name||my_ship->test_temp(my_power,it_power)==my_power){
            QMessageBox::StandardButton rb = QMessageBox::information(NULL, "Warn!", "You meet a horrible enemy, do you want to attack?", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            if(rb==QMessageBox::Yes){
                start_attack(enemyd);
            }
            else{
                ui->infote->append("R!U!N!");
                ui->infote->verticalScrollBar()->setValue(ui->infote->verticalScrollBar()->maximum());
            }

        }
        else
            start_attack(enemyd);
    }
    else if(des =="Federation"){
        Ship *enemyf = new Ship("Federation");
        string it_name = enemyf->get_ship_name();
        int it_power = enemyf->getPower();
        if(my_ship->test_temp(my_name,it_name) == my_name||my_ship->test_temp(my_power,it_power)==my_power){
            QMessageBox::StandardButton rb = QMessageBox::information(NULL, "Warn!", "You meet a horrible enemy, do you want to attack?", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            if(rb==QMessageBox::Yes){

                start_attack(enemyf);
            }
            else{
                ui->infote->append("R!U!N!");
                ui->infote->verticalScrollBar()->setValue(ui->infote->verticalScrollBar()->maximum());
            }

        }
        else
            start_attack(enemyf);
    }
    else if(des == "Lasers"){
        QMessageBox::StandardButton rb = QMessageBox::information(NULL, "Lucky", "Lasers can hurt enemy 5 power points each time, Do you want to change weapon?", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        if(rb==QMessageBox::Yes){

           my_ship->change_weapon("Lasers");
           ui->infote->append("Status of your ship: "+QString::fromStdString(my_ship->get_des())+"\nPower: "+QString::number(my_ship->getPower()));
           ui->infote->verticalScrollBar()->setValue(ui->infote->verticalScrollBar()->maximum());
           temp.currentRoom->itemsInRoom.clear();
        }

    }
    else if(des == "power +5"){
        ui->infote->append("Lucky! Here is no enemy!You got 5 power point!\n");
        my_ship->setPower(des);
        ui->infote->append("Status of your ship: "+QString::fromStdString(my_ship->get_des())+"\nPower: "+QString::number(my_ship->getPower()));
        ui->infote->verticalScrollBar()->setValue(ui->infote->verticalScrollBar()->maximum());
        temp.currentRoom->itemsInRoom.clear();
    }
    else if(des == "power +10"){
          ui->infote->append("Lucky! Here is no enemy!You got 10 power point!\n");
        my_ship->setPower(des);
        ui->infote->append("Status of your ship: "+QString::fromStdString(my_ship->get_des())+"\nPower: "+QString::number(my_ship->getPower()));
        ui->infote->verticalScrollBar()->setValue(ui->infote->verticalScrollBar()->maximum());
        temp.currentRoom->itemsInRoom.clear();

    }
    else if(des == "door"){
        if(my_ship->get_key){
            QMessageBox::StandardButton rb = QMessageBox::information(NULL, "Lucky", "You find the door, open the door the you can win!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            if(rb==QMessageBox::Yes){

               ui->infote->append("You win!");
               is_start = false;
               ui->infote->verticalScrollBar()->setValue(ui->infote->verticalScrollBar()->maximum());

            }
            else{
                MainWindow::close();
            }

        }
        else{
            ui->infote->append("You find the door, you have to find the key then you will win!");
            ui->infote->verticalScrollBar()->setValue(ui->infote->verticalScrollBar()->maximum());

        }
    }
    else if(des == "key"){
          ui->infote->append("Lucky! Here is no enemy!");
        ui->infote->append("You find the key!");

        temp.currentRoom->itemsInRoom.clear();
        my_ship->get_key=true;


    }

    }
}


void MainWindow::start_attack(Ship *enemy){
    ui->infote->append("\nstart attack ");
    while(!my_ship->is_kill(my_ship->getPower())&& !enemy->is_kill(enemy->getPower())){
        Clock c1(2),c2(2);
        int t= rand()%2;
        if(t==0){
            if(c1.run()){
                enemy->attack(my_ship,1);
                ui->infote->append("You got the attack from enemy ship\nYour power now is "+QString::number(my_ship->getPower()));
                 QApplication::processEvents();
                 ui->infote->verticalScrollBar()->setValue(ui->infote->verticalScrollBar()->maximum());

            }
        }
        else if(t==1){
            if(c2.run()){
                if(my_ship->check_weapon().compare("Missiles")==0)
                    my_ship->attack(enemy,3);
                else if(my_ship->check_weapon().compare("Lasers")==0)
                    my_ship->attack(enemy,5);
                ui->infote->append("You attack enemy ship\nEnemy's power is "+QString::number(enemy->getPower()));
                 QApplication::processEvents();

                ui->infote->verticalScrollBar()->setValue(ui->infote->verticalScrollBar()->maximum());

            }
        }

    }
    if(my_ship->is_kill(my_ship->getPower())){

        is_start = false;
        QMessageBox::about(NULL, "About", "Sorry you are dead!");

    }
    else if(enemy->is_kill(enemy->getPower())){
        ui->infote->append("You beat enemy!Now go to next place, hope you can find the key!");
        ui->infote->verticalScrollBar()->setValue(ui->infote->verticalScrollBar()->maximum());
        temp.currentRoom->itemsInRoom.clear();

    }

    my_ship->setPower(10,"+");
    enemy->setPower(10,"+");

    ui->infote->append("Now you are in "+QString::fromStdString(temp.currentRoom->longDescription())+"\nStatus of your ship: "+QString::fromStdString(my_ship->get_des())+"Power: "+QString::number(my_ship->getPower()));
    ui->infote->verticalScrollBar()->setValue(ui->infote->verticalScrollBar()->maximum());


}


void MainWindow::on_westbt_clicked()
{
    ui->infote->append("\n");
    if(is_start==false)
            ui->infote->append("please enter the name of your ship and click start");
    else{
        Room* nextRoom = temp.currentRoom->nextRoom("west");

        if (nextRoom == NULL)
            ui->infote->append("You can not go there.");
        else {
            temp.currentRoom = nextRoom;
            ui->infote->append(QString::fromStdString(temp.currentRoom->longDescription()));
            if(temp.currentRoom->itemsInRoom.size()==1)
                MainWindow::check_Item(temp.currentRoom->itemsInRoom[0].getShortDescription());
            else if(temp.currentRoom->itemsInRoom.size()==0){
                ui->infote->append("There is no item in this room, go to next room.");
                ui->infote->verticalScrollBar()->setValue(ui->infote->verticalScrollBar()->maximum());
            }
            else{
                MainWindow::check_Item(temp.currentRoom->itemsInRoom[0].getShortDescription());

                MainWindow::check_Item(temp.currentRoom->itemsInRoom[1].getShortDescription());

                }

            }
    }
}
void MainWindow::on_northbt_clicked()
{
    ui->infote->append("\n");
    if(is_start==false)
            ui->infote->append("please enter the name of your ship and click start");
    else{
        Room* nextRoom = temp.currentRoom->nextRoom("north");


        if (nextRoom == NULL){
        ui->infote->append("You can not go there.");
        ui->infote->verticalScrollBar()->setValue(ui->infote->verticalScrollBar()->maximum());
        }

        else {
            temp.currentRoom = nextRoom;
            ui->infote->append(QString::fromStdString(temp.currentRoom->longDescription()));
            //attack
            if(temp.currentRoom->itemsInRoom.size()==1)
                MainWindow::check_Item(temp.currentRoom->itemsInRoom[0].getShortDescription());
            else if(temp.currentRoom->itemsInRoom.size()==0){
                ui->infote->append("There is no item in this room, go to next room.");
                ui->infote->verticalScrollBar()->setValue(ui->infote->verticalScrollBar()->maximum());
            }

            else{
                MainWindow::check_Item(temp.currentRoom->itemsInRoom[0].getShortDescription());

                MainWindow::check_Item(temp.currentRoom->itemsInRoom[1].getShortDescription());

                }

            }
    }
}
void MainWindow::on_southbt_clicked()
{
    ui->infote->append("\n");
    if(is_start==false)
            ui->infote->append("please enter the name of your ship and click start");
    else{
        Room* nextRoom = temp.currentRoom->nextRoom("south");

        if (nextRoom == NULL){
        ui->infote->append("You can not go there.");
        ui->infote->verticalScrollBar()->setValue(ui->infote->verticalScrollBar()->maximum());
        }
        else {
            temp.currentRoom = nextRoom;
            ui->infote->append(QString::fromStdString(temp.currentRoom->longDescription()));
            if(temp.currentRoom->itemsInRoom.size()==1)
                MainWindow::check_Item(temp.currentRoom->itemsInRoom[0].getShortDescription());
            else if(temp.currentRoom->itemsInRoom.size()==0){
                ui->infote->append("There is no item in this room, go to next room.");
                 ui->infote->verticalScrollBar()->setValue(ui->infote->verticalScrollBar()->maximum());
            }

            else{
                MainWindow::check_Item(temp.currentRoom->itemsInRoom[0].getShortDescription());

                MainWindow::check_Item(temp.currentRoom->itemsInRoom[1].getShortDescription());

                }

            }
        }
}

void MainWindow::on_eastbt_clicked()
{
    ui->infote->append("\n");
    if(is_start==false)
            ui->infote->append("please enter the name of your ship and click start");
    else{
    Room* nextRoom = temp.currentRoom->nextRoom("east");

    if (nextRoom == NULL){
    ui->infote->append("You can not go there.");
    ui->infote->verticalScrollBar()->setValue(ui->infote->verticalScrollBar()->maximum());
    }
    else {
        temp.currentRoom = nextRoom;
        ui->infote->append(QString::fromStdString(temp.currentRoom->longDescription()));
        if(temp.currentRoom->itemsInRoom.size()==1)
            MainWindow::check_Item(temp.currentRoom->itemsInRoom[0].getShortDescription());
        else if(temp.currentRoom->itemsInRoom.size()==0){
            ui->infote->append("There is no item in this room, go to next room.");
             ui->infote->verticalScrollBar()->setValue(ui->infote->verticalScrollBar()->maximum());
        }

        else{
            MainWindow::check_Item(temp.currentRoom->itemsInRoom[0].getShortDescription());

            MainWindow::check_Item(temp.currentRoom->itemsInRoom[1].getShortDescription());

            }

        }
    }

}

void MainWindow::on_telebt_clicked()
{
    ui->infote->append("\n");
    if(is_start==false)
            ui->infote->append("please enter the name of your ship and click start");
    else{
    int teleportToThisRoom = rand()%10-1;

   for(int i=0;i<10;i++){
       if(temp.my_rooms[i]->shortDescription().compare(temp.my_roomsDes[teleportToThisRoom])==0)
            {
           temp.currentRoom = temp.my_rooms[i];
           ui->infote->append(QString::fromStdString(temp.currentRoom->longDescription()));
           if(temp.currentRoom->itemsInRoom.size()==1)
               MainWindow::check_Item(temp.currentRoom->itemsInRoom[0].getShortDescription());
           else if(temp.currentRoom->itemsInRoom.size()==0){
               ui->infote->append("There is no item in this room, go to next room.");
                ui->infote->verticalScrollBar()->setValue(ui->infote->verticalScrollBar()->maximum());
           }

           else{
               MainWindow::check_Item(temp.currentRoom->itemsInRoom[0].getShortDescription());

               MainWindow::check_Item(temp.currentRoom->itemsInRoom[1].getShortDescription());

               }

            }
        }
    }

}

void MainWindow::on_quitbt_clicked()
{

    MainWindow::close();
}
