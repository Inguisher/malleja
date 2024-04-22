#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    this->show();
    this->exec();
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_LogoutButton_clicked()
{

}

void MainMenu::on_WithdrawButton_clicked()
{
    TakeMoney *Withdraw;
    Withdraw = new TakeMoney;
    Withdraw->show();


}

void MainMenu::on_TransactionsButton_clicked()
{
    Transactions * Event;
    Event = new Transactions;
    Event->show();

}

void MainMenu::on_BalanceButton_clicked()
{
    Balance * BalanceObj;
    BalanceObj = new Balance;
    BalanceObj->show();

}
