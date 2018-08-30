#include "UserLogPacket.h"
#include <QBuffer>
#include <QDebug>

UserLogPacket::UserLogPacket()
{
#ifndef NDEBUG
    qDebug() << "A UserLogPacket instance created";
#endif
}

UserLogPacket::UserLogPacket(const UserLogPacket& origin):
    _username(origin._username),
    _pass(origin._pass)
{
#ifndef NDEBUG
    qDebug() << "A UserLogPacket instance copied";
#endif
}

UserLogPacket::~UserLogPacket()
{
#ifndef NDEBUG
    qDebug() << "A UserLogPacket instance deleted";
#endif
}

QByteArray UserLogPacket::specificDump() const
{
    QByteArray data;
    const char* username(_username.toStdString().c_str());
    const char* pass(_pass.toStdString().c_str());
    data.append(username, strlen(username) + 1);
    data.append(pass, strlen(pass) + 1);
    return data;
}

void UserLogPacket::specificLoad(QBuffer& buffer)
{
    QByteArray strings = buffer.readAll();
    _username = QString(strings.data());
    strings.remove(0, _username.size() + 1);
    _pass = QString(strings.data());
}

char UserLogPacket::specificGetID() const
{
    return 1;
}
