#ifndef _USER_GET_BNGS_PACKET_
#define _USER_GET_BNGS_PACKET_
#include "../Packet.h"

class UserGetBngsPacket : public Packet
{
    Q_OBJECT
private:
    virtual QByteArray specificDump() const;
    virtual void specificLoad(QBuffer&);
    virtual char specificGetID() const;
public:
    UserGetBngsPacket();
    UserGetBngsPacket(const UserGetBngsPacket&);
    ~UserGetBngsPacket();
};

#endif
