#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <QDialog>
#include <QDebug>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "restapi.h"

namespace Ui {
class Transactions;
}

class Transactions : public QDialog
{
    Q_OBJECT

public:
    explicit Transactions(QWidget *parent = nullptr);
    ~Transactions();

private slots:
    void on_LastButton_clicked();
    void on_NextButton_clicked();
    void TransactionInfo(QNetworkReply*);

private:
    Ui::Transactions *ui;
};

#endif // TRANSACTIONS_H
