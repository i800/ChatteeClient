#include "UserAddMessPacket.h"
#include <QBuffer>
#include <QDebug>

UserAddMessPacket::UserAddMessPacket()
{
#ifndef NDEBUG
    qDebug() << "A UserAddMessPacket instance created";
#endif
}

UserAddMessPacket::UserAddMessPacket(const UserAddMessPacket& origin):
    _text(origin._text),
    _to(origin._to)
{
#ifndef NDEBUG
    qDebug() << "A UserAddMessPacket instance copied";
#endif
}

UserAddMessPacket::~UserAddMessPacket()
{
#ifndef NDEBUG
    qDebug() << "A UserAddMessPacket instance deleted";
#endif
}

QByteArray UserAddMessPacket::specificDump() const
{
    QByteArray data;
    const char* text(_text.toStdString().c_str());
    const char* to(_to.toStdString().c_str());
    data.append(text, strlen(text) + 1);
    data.append(to, strlen(to) + 1);
    return data;
}

void UserAddMessPacket::specificLoad(QBuffer& buffer)
{
    QByteArray strings = buffer.readAll();
    _text = QString(strings.data());
    strings.remove(0, _text.size() + 1);
    _to = QString(strings.data());
}

char UserAddMessPacket::specificGetID() const
{
    return 3;
}
