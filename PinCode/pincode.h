#ifndef PINCODE_H
#define PINCODE_H

#include "PinCode_global.h"
#include "pincodeinput.h"

class PINCODE_EXPORT PinCode : public PinCodeInput
{
public:
    PinCode();
    ~PinCode();
    QString ValueRetrieval();

public slots:


private:
};

#endif // PINCODE_H
