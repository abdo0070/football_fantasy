QT       += core gui sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clubs.cpp \
    home.cpp \
    leagues.cpp \
    main.cpp \
    mainwindow.cpp \
    matches.cpp \
    matches_players.cpp \
    players.cpp \
    rounds.cpp \
    signup.cpp \
    teams.cpp \
    teams_players.cpp \
    users.cpp

HEADERS += \
    clubs.h \
    data.h \
    home.h \
    leagues.h \
    mainwindow.h \
    matches.h \
    matches_players.h \
    players.h \
    rounds.h \
    signup.h \
    teams.h \
    teams_players.h \
    users.h

FORMS += \
    home.ui \
    mainwindow.ui \
    signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    background.qrc

DISTFILES += \
    background/FC_Barcelona_(crest).svg.png
