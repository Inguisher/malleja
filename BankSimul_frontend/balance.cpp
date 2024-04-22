#include "balance.h"
#include "ui_balance.h"

Balance::Balance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Balance)
{
    ui->setupUi(this);
}

Balance::~Balance()
{
    delete ui;
}

void Balance::on_ShowBalanceButton_clicked()
{   QString AccountID = "3";
    RestApi * Api;
    Api = new RestApi;
    connect(Api, SIGNAL(BalanceInfoToExe(QNetworkReply *)), this, SLOT(BalanceSlot(QNetworkReply *)));
    Api->getBalance(AccountID);
}

void Balance::BalanceSlot(QNetworkReply * reply)
{
    QByteArray Info = reply->readAll();
    QJsonDocument json_doc=QJsonDocument::fromJson(Info);
    QJsonObject json_obj=json_doc.object();
    QString Balance = QString::number(json_obj["Balance"].toInt());
    ui->BalanceAmount->setText(Info);
    qDebug() << Info;
}

