#include "Core/Core.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Core core;
    core.start();
    return a.exec();
}
