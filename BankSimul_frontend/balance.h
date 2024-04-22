#ifndef BALANCE_H
#define BALANCE_H

#include <QDialog>
#include <QDebug>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "restapi.h"

namespace Ui {
class Balance;
}

class Balance : public QDialog
{
    Q_OBJECT

public:
    explicit Balance(QWidget *parent = nullptr);
    ~Balance();

private slots:
    void on_ShowBalanceButton_clicked();
    void BalanceSlot(QNetworkReply *);
private:
    Ui::Balance *ui;
};

#endif // BALANCE_H
