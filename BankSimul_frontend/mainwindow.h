#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "mainmenu.h"


#include "pincode.h"




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void LoginCheck();
    void CloseCard();

private slots:
    void LoginSlot(QNetworkReply *reply);
    void CloseStatus(QNetworkReply *reply);

private:
    Ui::MainWindow *ui;
    bool CardInsert = true;
    QString RFIDvalue;
    int LoginTry = 0;
    QByteArray LoginAccess;
    int y;
};
#endif // MAINWINDOW_H
