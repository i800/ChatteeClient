#ifndef _PACKET_HANDLER_
#define _PACKET_HANDLER_
#include "Protocol/Packets/UserRegPacket.h"
#include "Protocol/Packets/UserLogPacket.h"
#include "Protocol/Packets/UserAddChatPacket.h"
#include "Protocol/Packets/UserAddMessPacket.h"

class PacketHandler : public QObject
{
    Q_OBJECT
private:
    PacketHandler(const PacketHandler&) = delete;
    PacketHandler& operator=(const PacketHandler&) = delete;
public:
    // Packet id equals to index in the enum.
    enum PacketMeta
    {
        USER_REG,
        USER_LOG,
        USER_ADD_CHAT,
        USER_ADD_MESS
    };
    PacketHandler();
    ~PacketHandler();
    bool isValidPacket(const QByteArray&);
    UserRegPacket makeUserRegPacket(QByteArray&);
    UserLogPacket makeUserLogPacket(QByteArray&);
    UserAddChatPacket makeUserAddChatPacket(QByteArray&);
    UserAddMessPacket makeUserAddMessPacket(QByteArray&);
    PacketMeta getPacketMeta(const QByteArray&);
    quint16 getPacketSize(const QByteArray&);
};

#endif
