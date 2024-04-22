QT       += core gui
QT +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    balance.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    takemoney.cpp \
    transactions.cpp \


HEADERS += \
    balance.h \
    mainmenu.h \
    mainwindow.h \
    takemoney.h \
    transactions.h \


FORMS += \
    balance.ui \
    mainmenu.ui \
    mainwindow.ui \
    takemoney.ui \
    transactions.ui \


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target





win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../PinCode/build-PinCode-Desktop_Qt_5_15_0_MinGW_32_bit-Debug/release/ -lPinCode
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../PinCode/build-PinCode-Desktop_Qt_5_15_0_MinGW_32_bit-Debug/debug/ -lPinCode

INCLUDEPATH += $$PWD/../PinCode
DEPENDPATH += $$PWD/../PinCode

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../restApi/build-restApi-Desktop_Qt_5_15_0_MinGW_32_bit-Debug/release/ -lrestApi
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../restApi/build-restApi-Desktop_Qt_5_15_0_MinGW_32_bit-Debug/debug/ -lrestApi

INCLUDEPATH += $$PWD/../restApi
DEPENDPATH += $$PWD/../restApi
