#ifndef CHARACTER_H
#define CHARACTER_H

#include "dynamicobject.h"
#include "movableobject.h"

#include <QVector>
#include <QDebug>


class Character : public DynamicObject, public MovableObject
{
public:
    Character(QVector<int> position, QVector<int> size, int speed, int durability);

    virtual void update() = 0;
    virtual void onDurabilityLoss() = 0;
    virtual void move(QVector<int> nextPosition) = 0;
};

#endif // CHARACTER_H
