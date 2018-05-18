#ifndef _USER_ADD_MESS_PACKET_
#define _USER_ADD_MESS_PACKET_
#include "../Packet.h"

class UserAddMessPacket : public Packet
{
    Q_OBJECT
private:
    QString _text;
    QString _to;
    virtual QByteArray specificDump() const;
    virtual void specificLoad(QBuffer&);
    virtual char specificGetID() const;
public:
    UserAddMessPacket();
    UserAddMessPacket(const UserAddMessPacket&);
    ~UserAddMessPacket();

    inline QString text() const { return _text; }
    inline QString to() const { return _to; }

    inline QString& text() { return _text; }
    inline QString& to() { return _to; }
};

#endif
