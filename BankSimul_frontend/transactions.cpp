#include "transactions.h"
#include "ui_transactions.h"

Transactions::Transactions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Transactions)
{
    ui->setupUi(this);
}

Transactions::~Transactions()
{
    delete ui;
}

void Transactions::on_LastButton_clicked()
{

}

void Transactions::on_NextButton_clicked()
{
    QString AccountID = "3";
    RestApi * Api;
    Api = new RestApi;
    connect(Api, SIGNAL(actionInfoToExe(QNetworkReply *)), this, SLOT(TransactionInfo(QNetworkReply *)));
    Api->getAccountActions(AccountID);

}

void Transactions::TransactionInfo(QNetworkReply * reply)
{
    QByteArray Info = reply->readAll();
    QJsonDocument json_doc=QJsonDocument::fromJson(Info);
    QJsonObject json_obj=json_doc.object();
    QString Transactions = QString::number(json_obj["actionid"].toInt())+" "+json_obj["Description"].toString()+" "+json_obj["Time"].toString()+" "+QString::number(json_obj["Amount"].toDouble())+ "\r\n";
    ui->LineEdit->setText(Transactions);
}


