#include <QDebug>
#include "Protocol/PacketHandler.h"
#include "Protocol/Packets/UserRegPacket.h"

PacketHandler::PacketHandler()
{
#ifndef NDEBUG
    qDebug() << "Packet handler created";
#endif
}

PacketHandler::~PacketHandler()
{
#ifndef NDEBUG
    qDebug() << "Packet handler deleted";
#endif
}

bool PacketHandler::isValidPacket(const QByteArray& data)
{
    return data.length() < 3 ? false
        : getPacketSize(data) <= (data.length() - sizeof(char) - sizeof(quint16));
}

UserRegPacket PacketHandler::makeUserRegPacket(QByteArray& data)
{
    UserRegPacket packet;
    packet.load(data);
    return packet;
}

UserLogPacket PacketHandler::makeUserLogPacket(QByteArray& data)
{
    UserLogPacket packet;
    packet.load(data);
    return packet;
}

UserAddChatPacket PacketHandler::makeUserAddChatPacket(QByteArray& data)
{
    UserAddChatPacket packet;
    packet.load(data);
    return packet;
}

UserAddMessPacket PacketHandler::makeUserAddMessPacket(QByteArray& data)
{
    UserAddMessPacket packet;
    packet.load(data);
    return packet;
}

PacketHandler::PacketMeta PacketHandler::getPacketMeta(const QByteArray& arr)
{
    return (PacketMeta)(*arr.data());
}

quint16 PacketHandler::getPacketSize(const QByteArray& arr)
{
    return *(reinterpret_cast<const quint16*>((arr.data() + 1)));
}
