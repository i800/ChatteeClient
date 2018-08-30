#ifndef _USER_REG_PACKET_
#define _USER_REG_PACKET_
#include "../Packet.h"

class UserRegPacket : public Packet
{
    Q_OBJECT
private:
    QString _username;
    QString _bio;
    QString _email;
    QString _pass;
    virtual QByteArray specificDump() const;
    virtual void specificLoad(QBuffer&);
    virtual char specificGetID() const;
public:
    UserRegPacket();
    UserRegPacket(const UserRegPacket&);
    ~UserRegPacket();

    inline const QString& username() const { return _username; }
    inline const QString& bio() const { return _bio; }
    inline const QString& email() const { return _email; }
    inline const QString& pass() const { return _pass; }

    inline QString& username() { return _username; }
    inline QString& bio() { return _bio; }
    inline QString& email() { return _email; }
    inline QString& pass() { return _pass; }
};

#endif
