#include "UserAddChatPacket.h"
#include <QBuffer>
#include <QDebug>

UserAddChatPacket::UserAddChatPacket()
{
#ifndef NDEBUG
    qDebug() << "A UserAddChatPacket instance created";
#endif
}

UserAddChatPacket::UserAddChatPacket(const UserAddChatPacket& origin):
    _to(origin._to)
{
#ifndef NDEBUG
    qDebug() << "A UserAddChatPacket instance copied";
#endif
}

UserAddChatPacket::~UserAddChatPacket()
{
#ifndef NDEBUG
    qDebug() << "A UserAddChatPacket instance deleted";
#endif
}

QByteArray UserAddChatPacket::specificDump() const
{
    QByteArray data;
    const char* to(_to.toStdString().c_str());
    data.append(to, strlen(to) + 1);
    return data;
}

void UserAddChatPacket::specificLoad(QBuffer& buffer)
{
    _to = QString(buffer.readAll().data());
}

char UserAddChatPacket::specificGetID() const
{
    return 2;
}
