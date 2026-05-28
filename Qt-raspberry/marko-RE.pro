QT += core gui widgets network

CONFIG += c++11

SOURCES += \
    main.cpp \
    dialog.cpp \
    game.cpp

HEADERS += \
    dialog.h \
    game.h

target.path = /home/pi/$$TARGET
INSTALLS += target
