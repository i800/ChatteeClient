#include "UserGetChatPacket.h"
#include <QBuffer>
#include <QDebug>

UserGetChatPacket::UserGetChatPacket()
{
#ifndef NDEBUG
    qDebug() << "A UserGetChatPacket instance created";
#endif
}

UserGetChatPacket::UserGetChatPacket(const UserGetChatPacket& origin):
    _to(origin._to)
{
#ifndef NDEBUG
    qDebug() << "A UserGetChatPacket instance copied";
#endif
}

UserGetChatPacket::~UserGetChatPacket()
{
#ifndef NDEBUG
    qDebug() << "A UserGetChatPacket instance deleted";
#endif
}

QByteArray UserGetChatPacket::specificDump() const
{
    QByteArray data;
    const char* to(_to.toStdString().c_str());
    data.append(to, strlen(to) + 1);
    return data;
}

void UserGetChatPacket::specificLoad(QBuffer& buffer)
{
    _to = QString(buffer.readAll().data());
}

char UserGetChatPacket::specificGetID() const
{
    return 4;
}
