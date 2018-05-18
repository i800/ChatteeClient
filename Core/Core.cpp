#include "Core.h"
#include "ui_LogFrame.h"
#include "ui_RegFrame.h"
#include "Protocol/Packets/UserRegPacket.h"
#include "Protocol/Packets/UserLogPacket.h"
#include "Protocol/Packets/UserGetChatPacket.h"
#include "Protocol/Packets/UserGetBngsPacket.h"
#include <QDebug>
#include <QMessageBox>

Core::Core():
    _isPending(true),
    _connection(new QTcpSocket(this))
{
    // In case of failed connection.
    connect(_connection,
        QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
        this, &Core::reactOnDisruption);
    connect(_regFrame.ui->switchToLog, &QPushButton::clicked,
            this, &Core::switchToLog);
    connect(_regFrame.ui->submitButton, &QPushButton::clicked,
            this, &Core::tryRegister);
    connect(_logFrame.ui->switchToReg, &QPushButton::clicked,
            this, &Core::switchToReg);
    connect(_logFrame.ui->submitButton, &QPushButton::clicked,
            this, &Core::tryLogin);

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
    UserGetBngsPacket p;
    _connection->write(p.dump());
    _connection->flush();
}

void Core::processMessage()
{
    QTcpSocket* pSender = qobject_cast<QTcpSocket*>(sender());
    QByteArray message = pSender->readAll();
    QDataStream in(&message, QIODevice::ReadWrite);
    QList<QString> list;
    in >> list;

    for (QString& s : list)
    {
        qDebug() << s;
    }
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

void Core::tryRegister()
{
    // TODO: Validation.
    UserRegPacket packet;
    packet.username() = _regFrame.ui->lineEdit->text();
    packet.bio() = _regFrame.ui->lineEdit_2->text();
    packet.email() = _regFrame.ui->lineEdit_3->text();
    packet.pass() = _regFrame.ui->lineEdit_4->text();
    _connection->write(packet.dump());
    _connection->flush();
    _connection->blockSignals(true);
    _connection->waitForReadyRead();
    if (_connection->readAll().data()[0] == char(1))
    {
        switchToLog();
    }
    else
    {
        QMessageBox::information(0, "Error", "Cannot create a user with such data");
    }
    _connection->blockSignals(false);
}

void Core::tryLogin()
{
    UserLogPacket packet;
    packet.username() = _logFrame.ui->lineEdit->text();
    packet.pass() = _logFrame.ui->lineEdit_2->text();
    _connection->write(packet.dump());
    _connection->flush();
    _connection->blockSignals(true);
    _connection->waitForReadyRead();
    if (_connection->readAll().data()[0] == char(1))
    {
        _mainWindow.show();
        _logFrame.close();
        test();
    }
    else
    {
        QMessageBox::information(0, "Error", "Invlaid useraname/password");
    }
    _connection->blockSignals(false);
}
