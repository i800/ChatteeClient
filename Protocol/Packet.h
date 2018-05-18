#ifndef _PACKET_
#define _PACKET_
#include <QObject>
#include <QDebug>

class QBuffer;

class Packet : public QObject
{
    Q_OBJECT
private:
    virtual QByteArray specificDump() const {qDebug() << "f"; return QByteArray();}
    virtual void specificLoad(QBuffer&) = 0;
    virtual char specificGetID() const = 0;
public:
    virtual ~Packet() {}
    // NVI
    QByteArray dump() const;
    void load(QByteArray&);
};

#endif
