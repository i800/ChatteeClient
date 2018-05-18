#include "Core.h"
#include <QDebug>

Core::Core():
    _isPending(true),
    _connection(new QTcpSocket(this))
{
    // In case of failed connection.
    connect(_connection,
        QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
        this, &Core::reactOnDisruption);

    _logFrame.show();

#ifndef NDEBUG
    qDebug() << "Core created.";
#endif
}

Core::~Core()
{
    _connection->close();
    delete _connection;

#ifndef NDEBUG
    qDebug() << "Core deleted.";
#endif
}

void Core::start(const char* host, const quint16 port)
{
    _connection->abort();
    _connection->connectToHost(host, port);
    _isPending = !_connection->isOpen();

    connect(_connection, &QTcpSocket::readyRead,
            this, &Core::processMessage);
}

void Core::test()
{
    _connection->write("Hello");
    _connection->flush();
}

void Core::processMessage()
{
    QTcpSocket* pSender = qobject_cast<QTcpSocket*>(sender());
    QByteArray message = pSender->readAll();
    qDebug() << message;
}

void Core::reactOnDisruption()
{
    // emit disruption();

#ifndef NDEBUG
    qDebug() << "Connection disrupted.";
#endif
}
