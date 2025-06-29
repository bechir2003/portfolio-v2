QT       += core gui sql texttospeech
QT += printsupport
QT += core gui widgets charts
QT += svg serialport

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
    Arduino/arduino.cpp \
    Arduino/arduino2.cpp \
    Connexion_Bd/connexion_bd.cpp \
    Gestion_Charite/charite.cpp \
    Gestion_Charite/gestion_charite.cpp \
    Gestion_Charite/sta.cpp \
    Gestion_Evenement/calendriers.cpp \
    Gestion_Evenement/evenement.cpp \
    Gestion_Evenement/gestion_evenement.cpp \
    Gestion_Evenement/statisss.cpp \
    Gestion_Oeuvre/dialog.cpp \
    Gestion_Oeuvre/gestion_oeuvre.cpp \
    Gestion_Oeuvre/oeuvre.cpp \
    Gestion_Participants/gestion_participant.cpp \
    Gestion_Participants/participant.cpp \
    Gestion_Participants/participation.cpp \
    Gestion_Participants/statistique.cpp \
    Gestion_Personnel/employee.cpp \
    Gestion_Personnel/forgetp.cpp \
    Gestion_Personnel/gestion_personnel.cpp \
    Gestion_Personnel/qrcode.cpp \
    His_Achat/gestion_achat.cpp \
    His_Achat/his_achat.cpp \
    Menu/menu.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Arduino/arduino.h \
    Arduino/arduino2.h \
    Connexion_Bd/connexion_bd.h \
    Gestion_Charite/charite.h \
    Gestion_Charite/gestion_charite.h \
    Gestion_Charite/sta.h \
    Gestion_Evenement/calendriers.h \
    Gestion_Evenement/evenement.h \
    Gestion_Evenement/gestion_evenement.h \
    Gestion_Evenement/statisss.h \
    Gestion_Oeuvre/dialog.h \
    Gestion_Oeuvre/gestion_oeuvre.h \
    Gestion_Oeuvre/oeuvre.h \
    Gestion_Participants/gestion_participant.h \
    Gestion_Participants/participant.h \
    Gestion_Participants/participation.h \
    Gestion_Participants/statistique.h \
    Gestion_Personnel/employee.h \
    Gestion_Personnel/forgetp.h \
    Gestion_Personnel/gestion_personnel.h \
    Gestion_Personnel/qrcode.h \
    His_Achat/gestion_achat.h \
    His_Achat/his_achat.h \
    Menu/menu.h \
    mainwindow.h

FORMS += \
    Gestion_Charite/gestion_charite.ui \
    Gestion_Charite/sta.ui \
    Gestion_Evenement/calendriers.ui \
    Gestion_Evenement/gestion_evenement.ui \
    Gestion_Evenement/statisss.ui \
    Gestion_Oeuvre/dialog.ui \
    Gestion_Oeuvre/gestion_oeuvre.ui \
    Gestion_Participants/gestion_participant.ui \
    Gestion_Participants/statistique.ui \
    Gestion_Personnel/forgetp.ui \
    Gestion_Personnel/gestion_personnel.ui \
    His_Achat/gestion_Achat.ui \
    His_Achat/gestion_achat.ui \
    Menu/menu.ui \
    mainwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    His_Achat/New Document texte.txt


