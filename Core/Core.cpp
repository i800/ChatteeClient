#include "Core.h"
#include "ui_LogFrame.h"
#include "ui_RegFrame.h"
#include "Protocol/Packets/UserLogPacket.h"
#include <QDebug>

Core::Core():
    _isPending(true),
    _connection(new QTcpSocket(this))
{
    // In case of failed connection.
    connect(_connection,
        QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
        this, &Core::reactOnDisruption);
    connect(_logFrame.ui->pushButton_2, &QPushButton::clicked,
            this, &Core::switchToReg);
    connect(_logFrame.ui->pushButton_2, &QPushButton::clicked,
            this, &Core::switchToLog);

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
    UserLogPacket p;
    p.username() = "u2";
    p.pass() = "p1";
    _connection->write(p.dump());
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

void Core::switchToReg()
{
    _regFrame.show();
    _logFrame.close();
}

void Core::switchToLog()
{
    _logFrame.show();
    _regFrame.close();
}
