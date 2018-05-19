#ifndef _CORE_
#define _CORE_
#include "UserState.h"
#include "GUI/MainWindow.h"
#include "GUI/LogFrame.h"
#include "GUI/RegFrame.h"
#include <QTcpSocket>

class Core : public QObject
{
    Q_OBJECT
private:
    bool _isPending;
    QString _session;
    QTcpSocket* _connection;
    UserState _userState;
    MainWindow _mainWindow;
    LogFrame _logFrame;
    RegFrame _regFrame;
    Core(const Core&) = delete;
    Core& operator=(const Core&) = delete;
public:
    explicit Core();
    ~Core();
    void start(const char* host = "localhost", const quint16 port = 45654);
    void test();
private slots:
    void processMessage();
    void reactOnDisruption();
    void switchToReg();
    void switchToLog();
    void tryRegister();
    void tryLogin();
    void getBindings();
    void getMessages();
    // Other reactions (...)
};

#endif
