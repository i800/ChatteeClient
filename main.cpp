#include "MainWindow.h"
#include "Client.h"
#include <QApplication>
#include <QtCore/QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Client client;
    Client client2;
    client.start();
    client2.start();
    w.show();
    client.test();
    return a.exec();
}
