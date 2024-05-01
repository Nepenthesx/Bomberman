#include "temporaryobject.h"


TemporaryObject::TemporaryObject(int lifetime)
{
    setTimer(lifetime);
}

void TemporaryObject::setTimer(int lifetime)
{
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(changeTimeoutStatus()));
    timer->setInterval(lifetime);
    timer->start();
}

void TemporaryObject::changeTimeoutStatus()
{
    isTimeout = true;
}
