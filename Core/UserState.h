#ifndef _USER_STATE_
#define _USER_STATE_
#include <QObject>

class UserState : public QObject
{
    Q_OBJECT
private:
    QList<QString> _activeMessages;
    QString* _activeUsername;
    UserState(const UserState&) = delete;
    UserState& operator=(const UserState&) = delete;
public:
    UserState();
    ~UserState();
    inline const QList<QString> activeMessages() const { return _activeMessages; }
    inline QString* activeUsername() const { return _activeUsername; }

    inline QList<QString>& activeMessages() { return _activeMessages; }
    inline QString* activeUsername() { return _activeUsername; }
};

#endif
