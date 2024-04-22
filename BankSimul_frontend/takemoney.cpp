#include "takemoney.h"
#include "ui_takemoney.h"

TakeMoney::TakeMoney(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TakeMoney)
{
    ui->setupUi(this);
}

TakeMoney::~TakeMoney()
{
    delete ui;
}


void TakeMoney::on_AcceptWithdrawButton_clicked()
{
    AccountID = "3";
    Amount = ui->MoneyInput->text();
    Amount.insert(0, QString("-"));
    RestApi * Api;
    Api = new RestApi;
    connect(Api, SIGNAL(TransactionInfoToExe(QNetworkReply *)), this, SLOT(WithdrawSlot(QNetworkReply *)));
    Api->transaction(AccountID, Amount);

    this->close();
}

void TakeMoney::WithdrawSlot(QNetworkReply * reply)
{
    qDebug() << "Money was taken from account, amount: " << reply;
}
