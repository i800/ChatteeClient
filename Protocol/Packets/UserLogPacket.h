#ifndef _USER_LOG_PACKET_
#define _USER_LOG_PACKET_
#include "../Packet.h"

class UserLogPacket : public Packet
{
    Q_OBJECT
private:
    QString _username;
    QString _pass;
    virtual QByteArray specificDump() const;
    virtual void specificLoad(QBuffer&);
    virtual char specificGetID() const;
public:
    UserLogPacket();
    UserLogPacket(const UserLogPacket&);
    ~UserLogPacket();

    inline const QString& username() const { return _username; }
    inline const QString& pass() const { return _pass; }

    inline QString& username() { return _username; }
    inline QString& pass() { return _pass; }
};

#endif
