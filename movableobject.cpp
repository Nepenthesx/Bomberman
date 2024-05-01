#include "movableobject.h"


MovableObject::MovableObject(int speed)
{
    setSpeed(speed);
}

int MovableObject::getSpeed()
{
    return speed;
}

void MovableObject::setSpeed(int speed)
{
    if (speed >= 0)
        this->speed = speed;
}
