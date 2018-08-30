#include "Packet.h"
#include <QBuffer>

// Non-virtual customizable method.
QByteArray Packet::dump() const
{
    const QByteArray data = specificDump();
    const char packid = specificGetID();
    const quint16 length = data.length();

    QByteArray toDump;
    toDump.append(packid);
    toDump.append((char*)&length, sizeof(quint16));
    toDump.append(data);
    return toDump;
}

void Packet::load(QByteArray& data)
{
    QBuffer buffer(&data);
    buffer.open(QBuffer::ReadOnly);
    char i(0);
    buffer.read(&i, sizeof(i));
    buffer.seek(buffer.pos() + sizeof(quint16));
    specificLoad(buffer);
}
