#include "UserRegPacket.h"
#include <QBuffer>
#include <QDebug>

UserRegPacket::UserRegPacket()
{
#ifndef NDEBUG
    qDebug() << "A UserRegPacket instance created";
#endif
}

UserRegPacket::UserRegPacket(const UserRegPacket& origin):
    _username(origin._username),
    _bio(origin._bio),
    _email(origin._email),
    _pass(origin._pass)
{
#ifndef NDEBUG
    qDebug() << "A UserRegPacket instance copied";
#endif
}

UserRegPacket::~UserRegPacket()
{
#ifndef NDEBUG
    qDebug() << "A UserRegPacket instance deleted";
#endif
}

QByteArray UserRegPacket::specificDump() const
{
    QByteArray data;
    const char* username(_username.toStdString().c_str());
    const char* bio(_bio.toStdString().c_str());
    const char* email(_email.toStdString().c_str());
    const char* pass(_pass.toStdString().c_str());
    data.append(username, strlen(username) + 1);
    data.append(bio, strlen(bio) + 1);
    data.append(email, strlen(email) + 1);
    data.append(pass, strlen(pass) + 1);
    return data;
}

void UserRegPacket::specificLoad(QBuffer& buffer)
{
    QByteArray strings = buffer.readAll();
    _username = QString(strings.data());
    strings.remove(0, _username.size() + 1);
    _bio = QString(strings.data());
    strings.remove(0, _bio.size() + 1);
    _email = QString(strings.data());
    strings.remove(0, _email.size() + 1);
    _pass = QString(strings.data());
}

char UserRegPacket::specificGetID() const
{
    return 0;
}
