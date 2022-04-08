QT       += core gui sql
QT += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

win32 {
        RC_FILE += file.rc
        OTHER_FILES += file.rc
}

SOURCES += \
    accountdialog.cpp \
    addflightdialog.cpp \
    admin.cpp \
    authorisationdialog.cpp \
    book.cpp \
    buyticketdialog.cpp \
    cashier.cpp \
    coredb.cpp \
    flight.cpp \
    flightsbook.cpp \
    main.cpp \
    maindialog.cpp \
    menuadmindialog.cpp \
    menucashierdialog.cpp \
    menudialog.cpp \
    passenger.cpp \
    registrationdialog.cpp \
    ticket.cpp \
    ticketdialog.cpp \
    ticketsbook.cpp \
    ticketslistdialog.cpp \
    user.cpp \
    usersbook.cpp

HEADERS += \
    accountdialog.h \
    addflightdialog.h \
    admin.h \
    authorisationdialog.h \
    book.h \
    buyticketdialog.h \
    cashier.h \
    coredb.h \
    flight.h \
    flightsbook.h \
    maindialog.h \
    menuadmindialog.h \
    menucashierdialog.h \
    menudialog.h \
    passenger.h \
    registrationdialog.h \
    ticket.h \
    ticketdialog.h \
    ticketsbook.h \
    ticketslistdialog.h \
    user.h \
    usersbook.h \
    validators.h

FORMS += \
    accountdialog.ui \
    addflightdialog.ui \
    authorisationdialog.ui \
    buyticketdialog.ui \
    maindialog.ui \
    menuadmindialog.ui \
    menucashierdialog.ui \
    menudialog.ui \
    registrationdialog.ui \
    ticketdialog.ui \
    ticketslistdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=

DISTFILES += \
    file.rc
