QT += core gui
QT += network
QT += core websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChatteeClient
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        GUI/MainWindow.cpp \
    Client.cpp \
    Protocol/Packets/UserAddChatPacket.cpp \
    Protocol/Packets/UserAddMessPacket.cpp \
    Protocol/Packets/UserLogPacket.cpp \
    Protocol/Packets/UserRegPacket.cpp \
    Protocol/Packet.cpp \
    Protocol/PacketHandler.cpp \
    GUI/LogFrame.cpp \
    GUI/RegFrame.cpp

HEADERS += \
        GUI/MainWindow.h \
    Client.h \
    Protocol/Packets/UserAddChatPacket.h \
    Protocol/Packets/UserAddMessPacket.h \
    Protocol/Packets/UserLogPacket.h \
    Protocol/Packets/UserRegPacket.h \
    Protocol/Packet.h \
    Protocol/PacketHandler.h \
    GUI/LogFrame.h \
    GUI/RegFrame.h

FORMS += \
        GUI/MainWindow.ui \
    GUI/LogFrame.ui \
    GUI/RegFrame.ui
