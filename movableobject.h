#ifndef MOVABLEOBJECT_H
#define MOVABLEOBJECT_H

#include <QVector>

class MovableObject
{
protected:
    int speed;
    int getSpeed();
    void setSpeed(int speed);

public:
    MovableObject(int speed);
    virtual void move(QVector<int> nextPosition) = 0;
};

#endif // MOVABLEOBJECT_H
