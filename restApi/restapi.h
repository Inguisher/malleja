#ifndef RESTAPI_H
#define RESTAPI_H

#include "restApi_global.h"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QDebug>

class RESTAPI_EXPORT RestApi: public QObject
{
    Q_OBJECT
public:
    RestApi();
    ~RestApi();
    void getBalance(QString);
    void getAllCards(QString credentials);
    void getAccountActions(QString id);
    void getAllCustomers(QString credentials);

    void getAccountById(QString credentials, int id);
    void getCardById(QString credentials, int id);
    void getActionById(QString credentials, int id);
    void getCustomerById(QString credentials, int id);

    void addAccount(QString accountNum, QString balance, QString opened, QString credentials);
    void addBankCard(QString cardNum, QString pinCode, QString accountID, QString credentials);
    void addCustomer(QString firstName, QString lastName, QString birthDate, QString address, QString phoneNum, QString credentials);

    void Login(QString, QString);
    void CloseCard(QString);
    void transaction(QString id, QString amount);

signals:
    void BalanceInfoToExe(QNetworkReply *);
    void accountInfoToExe(QNetworkReply *);
    void cardInfoToExe(QNetworkReply *);
    void actionInfoToExe(QNetworkReply *);
    void customerInfoToExe(QNetworkReply *);
    void LoginInfoToExe(QNetworkReply *);
    void TransactionInfoToExe(QNetworkReply *);

private slots:
    void BalanceFinished(QNetworkReply *);
    void accountFinished(QNetworkReply *);
    void cardFinished(QNetworkReply *);
    void actionFinished(QNetworkReply *);
    void customerFinished(QNetworkReply *);
    void LoginFinished(QNetworkReply *);
    void CardStatus(QNetworkReply *);
    void TransactionFinished(QNetworkReply *);

private:
    QNetworkAccessManager *allAccountsManager;
    QNetworkReply *allAccountsReply;

    QNetworkAccessManager *allCardsManager;
    QNetworkReply *allCardsReply;

    QNetworkAccessManager *allActionsManager;
    QNetworkReply *allActionsReply;

    QNetworkAccessManager *allCustomersManager;
    QNetworkReply *allCustomersReply;

    QNetworkAccessManager *CardManager;
    QNetworkReply *CardReply;

    QNetworkAccessManager *LoginManager;
    QNetworkReply *LoginReply;

    QNetworkAccessManager *TransactionManager;
    QNetworkReply *TransactionReply;

    QNetworkAccessManager *BalanceManager;
    QNetworkReply *BalanceReply;
};

#endif // RESTAPI_H
