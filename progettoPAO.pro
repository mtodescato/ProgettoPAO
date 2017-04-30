#-------------------------------------------------
#
# Project created by QtCreator 2016-12-19T20:51:41
#
#-------------------------------------------------


TARGET = progettoPAO
TEMPLATE = app
CONFIG += c++11

QT += core gui
QT += widgets
QT += xml

SOURCES += main.cpp \
    utente.cpp \
    admin.cpp \
    moderatore.cpp \
    listautenti.cpp \
    login.cpp \
    funzioniutili.cpp \
    astrattapubblicazione.cpp \
    pubblicazioneonline.cpp \
    astrattapubblicazionestampata.cpp \
    libro.cpp \
    articolorivista.cpp \
    filefactory.cpp \
    listapubblicazioni.cpp

HEADERS  += \
    utente.h \
    admin.h \
    moderatore.h \
    listautenti.h \
    login.h \
    funzioniutili.h \
    astrattapubblicazione.h \
    pubblicazioneonline.h \
    astrattapubblicazionestampata.h \
    libro.h \
    articolorivista.h \
    filefactory.h \
    listapubblicazioni.h

FORMS    +=

DISTFILES +=

RESOURCES += \
    risorse.qrc
