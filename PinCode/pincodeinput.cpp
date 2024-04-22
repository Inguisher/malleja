#include "pincodeinput.h"
#include "ui_pincodeinput.h"


PinCodeInput::PinCodeInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PinCodeInput)
//Suorittaa ikkunan avaamisen ja odottaa käyttäjän suoritusta.
{
    ui->setupUi(this);
    this->show();
    this->exec();

}

PinCodeInput::~PinCodeInput()
{
    delete ui;
}

//Palauttaa käyttäjän kenttään syöttämän arvon.
QString PinCodeInput::ValueReturn()
{
       return Value = ui->lineEditPin->text();
}

void PinCodeInput::on_buttonBox_accepted()
{

}

void PinCodeInput::on_buttonBox_rejected()
{

}
