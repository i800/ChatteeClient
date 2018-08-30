#include "Client.h"

Client::Client():
    _isPending(true),
    _connection(new QTcpSocket(this))
{
    // In case of failed connection.
    connect(_connection,
        QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
        this, &Client::reactOnDisruption);

#ifndef NDEBUG
    qDebug("Client created.");
#endif
}

Client::~Client()
{
    _connection->close();
    delete _connection;

#ifndef NDEBUG
    qDebug("Client deleted.");
#endif
}

void Client::start(const char* host, const unsigned short port)
{
    _connection->abort();
    _connection->connectToHost(host, port);
    _isPending = !_connection->isOpen();

    connect(_connection, &QTcpSocket::readyRead,
            this, &Client::processMessage);
}

void Client::test()
{
    _connection->write("Hello");
    _connection->flush();
}

void Client::processMessage()
{
    QTcpSocket* pSender = qobject_cast<QTcpSocket*>(sender());
    QByteArray message = pSender->readAll();
    qDebug(message);
}

void Client::reactOnDisruption()
{
    // emit disruption();

#ifndef NDEBUG
    qFatal("Connection disrupted.");
#endif
}
