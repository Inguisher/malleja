#ifndef PINCODEINPUT_H
#define PINCODEINPUT_H

#include <QDialog>
#include <QDebug>


namespace Ui {
class PinCodeInput;
}

class PinCodeInput : public QDialog
{
    Q_OBJECT

public:
    explicit PinCodeInput(QWidget *parent = nullptr);
    ~PinCodeInput();
    QString ValueReturn();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::PinCodeInput *ui;
    QString Value;
};

#endif // PINCODEINPUT_H
