#ifndef _USER_GET_CHAT_PACKET_
#define _USER_GET_CHAT_PACKET_
#include "../Packet.h"

class UserGetChatPacket : public Packet
{
    Q_OBJECT
private:
    QString _to;
    virtual QByteArray specificDump() const;
    virtual void specificLoad(QBuffer&);
    virtual char specificGetID() const;
public:
    UserGetChatPacket();
    UserGetChatPacket(const UserGetChatPacket&);
    ~UserGetChatPacket();

    inline QString to() const { return _to; }

    inline QString& to() { return _to; }
};

#endif
