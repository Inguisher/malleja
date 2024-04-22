#include "restapi.h"

RestApi::RestApi()
{


}


RestApi::~RestApi()
{

}


void RestApi::accountFinished(QNetworkReply *reply)
{
    emit accountInfoToExe(reply);
}

void RestApi::getAllCards(QString credentials)
{
    QJsonArray arr;
    QString site_url="http://localhost:3000/card";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    allCardsManager = new QNetworkAccessManager();

    allCardsReply = allCardsManager->get(request);

    emit cardInfoToExe(allCardsReply);
}

void RestApi::cardFinished(QNetworkReply*)
{

}




void RestApi::getAllCustomers(QString credentials)
{
    QJsonArray arr;
    QString site_url="http://localhost:3000/customer";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    allCardsManager = new QNetworkAccessManager();

    allCustomersReply = allCustomersManager->get(request);
    emit customerInfoToExe(allCustomersReply);
}


void RestApi::customerFinished(QNetworkReply*)
{

}

/* Get by id */

void RestApi::getAccountById(QString credentials, int id)
{
    QString idStr = QString::number(id);
    QString site_url = "http://localhost:3000/account/" + idStr;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    allAccountsManager = new QNetworkAccessManager();

    allAccountsReply = allAccountsManager->get(request);
}

void RestApi::getActionById(QString credentials, int id)
{
    QString idStr = QString::number(id);
    QString site_url="http://localhost:3000/action/" + idStr;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    allCardsManager = new QNetworkAccessManager();

    allActionsReply = allActionsManager->get(request);
}

void RestApi::getCardById(QString credentials, int id)
{
    QString idStr = QString::number(id);
    QString site_url="http://localhost:3000/card/" + idStr;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    allCardsManager = new QNetworkAccessManager();

    allCardsReply = allCardsManager->get(request);
}

void RestApi::getCustomerById(QString credentials, int id)
{
    QString idStr = QString::number(id);
    QString site_url="http://localhost:3000/customer/" + idStr;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    allCardsManager = new QNetworkAccessManager();

    allCustomersReply = allCustomersManager->get(request);
}

void RestApi::addAccount(QString AccountNum, QString Balance, QString Opened, QString credentials)
{
    QJsonObject json_obj;
    json_obj.insert("AccountNum", AccountNum);
    json_obj.insert("Balance", Balance);
    json_obj.insert("Opened", Opened);
    QString site_url = "http://localhost:3000/account";
    QNetworkRequest request(site_url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,
    "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );


}

void RestApi::Login(QString A, QString B)
{
    QJsonObject json_obj;
    json_obj.insert("CardNum",A);
    json_obj.insert("PinCode",B);
    QString site_url="http://localhost:3000/Login";
    QString credentials="root:root";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit());
    LoginManager = new QNetworkAccessManager(this);
    connect(LoginManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(LoginFinished(QNetworkReply*)));
    LoginReply = LoginManager->post(request, QJsonDocument(json_obj).toJson());
    qDebug() << "DLL Login end";

}

void RestApi::LoginFinished(QNetworkReply * reply)
{
    emit LoginInfoToExe(reply);
    reply->deleteLater();
}

void RestApi::CloseCard(QString A)
{

    QJsonObject json_obj;
    json_obj.insert("CardNum",A);
    QString site_url="http://localhost:3000/BankCard";
    QString credentials="root:root";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit());
    CardManager = new QNetworkAccessManager();
    connect(CardManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(CardStatus(QNetworkReply*)));
    CardReply = CardManager->put(request, QJsonDocument(json_obj).toJson());
    CardReply->deleteLater();
    CardManager->deleteLater();
}

void RestApi::CardStatus(QNetworkReply * reply)
{
    //emit CardStatusToExe(reply);
    reply->deleteLater();
}

void RestApi::TransactionFinished(QNetworkReply * reply)
{
    emit TransactionInfoToExe(reply);
}

void RestApi::transaction(QString id, QString amount)
{
    QJsonObject json_obj;
    json_obj.insert("AccountID", id);
    json_obj.insert("Amount", amount);
    QString site_url="http://localhost:3000/Action";
    QString credentials="root:root";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit());
    TransactionManager = new QNetworkAccessManager(this);
    connect(TransactionManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(TransactionFinished(QNetworkReply*)));
    TransactionReply = TransactionManager->post(request, QJsonDocument(json_obj).toJson());
}

void RestApi::getAccountActions(QString id)
{
    QJsonObject json_obj;
    json_obj.insert("AccountID",id);
    QString site_url="http://localhost:3000/Action";
    QString credentials="root:root";
    QNetworkRequest request((site_url));

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit());
    allActionsManager = new QNetworkAccessManager(this);
    connect(allActionsManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(actionFinished(QNetworkReply*)));
    allActionsReply = allActionsManager->get(request);

}


void RestApi::actionFinished(QNetworkReply * reply)
{
    emit actionInfoToExe(reply);
}

void RestApi::getBalance(QString id)
{
    QString site_url="http://localhost:3000/Account/"+id;
    QString credentials="root:root";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit());
    BalanceManager = new QNetworkAccessManager(this);
    connect(BalanceManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(BalanceFinished(QNetworkReply*)));
    BalanceReply = BalanceManager->get(request);

}

void RestApi::BalanceFinished(QNetworkReply * reply)
{
    emit BalanceInfoToExe(reply);
}
