#ifndef _USER_ADD_CHAT_PACKET_
#define _USER_ADD_CHAT_PACKET_
#include "../Packet.h"

class UserAddChatPacket : public Packet
{
    Q_OBJECT
private:
    QString _to;
    virtual QByteArray specificDump() const;
    virtual void specificLoad(QBuffer&);
    virtual char specificGetID() const;
public:
    UserAddChatPacket();
    UserAddChatPacket(const UserAddChatPacket&);
    ~UserAddChatPacket();

    inline QString to() const { return _to; }

    inline QString& to() { return _to; }
};

#endif
