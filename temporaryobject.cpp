#include "temporaryobject.h"


TemporaryObject::TemporaryObject(int lifetime)
{
    isTimeout = false;
    setTimer(lifetime);
}

void TemporaryObject::setTimer(int lifetime)
{
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(changeTimeoutStatus()));
    timer->setInterval(lifetime);
    timer->start();
}

bool TemporaryObject::checkTimeout()
{
    return isTimeout;
}

void TemporaryObject::changeTimeoutStatus()
{
    isTimeout = true;
    delete timer;
}
