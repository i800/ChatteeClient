#include "UserState.h"

UserState::UserState():
    _activeUsername(0)
{
#ifndef NDEBUG
    qDebug() << "The user state object created";
#endif
}

UserState::~UserState()
{
    delete _activeUsername;
#ifndef NDEBUG
    qDebug() << "The user state object deleted";
#endif
}
