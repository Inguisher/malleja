#ifndef TAKEMONEY_H
#define TAKEMONEY_H

#include <QDialog>
#include <QDebug>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "restapi.h"

namespace Ui {
class TakeMoney;
}

class TakeMoney : public QDialog
{
    Q_OBJECT

public:
    explicit TakeMoney(QWidget *parent = nullptr);
    ~TakeMoney();

public slots:


private slots:
    void on_AcceptWithdrawButton_clicked();
    void WithdrawSlot(QNetworkReply*);
private:
    Ui::TakeMoney *ui;
    QString Amount;
    QString AccountID;
};

#endif // TAKEMONEY_H
