#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->show();
    while (CardInsert) {
        RFIDvalue = "111";
        LoginCheck();

        qDebug() << LoginAccess;


        if (LoginAccess == "true") {
            qDebug() << "Pinkoodi oikein";
            MainMenu Menu;
        }
        if (LoginAccess == "false"){
            qDebug() << "Pinkoodi väärin";
        }
        if(!CardInsert){
            break;
        }
    }

    qDebug() << "ulkona ";

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LoginCheck() //lähetetään dll
{
    RestApi * Api;
    Api = new RestApi;
    QString PinCodeValue = PinCode().ValueRetrieval();
    connect(Api, SIGNAL(LoginInfoToExe(QNetworkReply *)), this, SLOT(LoginSlot(QNetworkReply *)));
    Api->Login(RFIDvalue, PinCodeValue);

    qDebug() << "STEP. 2";
}

void MainWindow::LoginSlot(QNetworkReply * reply)
{
    qDebug() << "STEP. 4";
    LoginAccess = reply->readAll();
    qDebug() << LoginAccess;

    if(LoginAccess.compare("-4078")==0 || LoginAccess.compare("")==0){
        qDebug()<<("Virhe tietokantayhteydessä");
    }
    if (LoginAccess == "false") {
        LoginTry++;
        qDebug() << LoginTry;
        if(LoginTry == 3) {
            LoginTry = 0;
            qDebug() << "reset";
            CardInsert = "false";
            //CloseCard();
            }
    }

    if (LoginAccess == "true"){
        LoginTry = 0;
    }


}

void MainWindow::CloseCard()
{
    RestApi * Api;
    Api = new RestApi;
    Api->CloseCard("111");
}

void MainWindow::CloseStatus(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;

    if(response_data.compare("-4078")==0 || response_data.compare("")==0){
        qDebug()<<("Virhe tietokantayhteydessä");
    }

}

