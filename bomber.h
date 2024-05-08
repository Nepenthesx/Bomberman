#ifndef BOMBER_H
#define BOMBER_H

#include "character.h"

class Bomber : public Character
{
public:enum BombType
    {
        Cross,
        Square
    };

protected:
    int bombCount = 0;
    int maxBombCount;
    int bombPower;
    Bomber::BombType bombType;

    void setMaxBombCount(int maxBombCount);
    void setBombPower(int bombPower);
    void setBombType(Bomber::BombType bombType);
public:
    Bomber(QVector<int> position, QVector<int> size, int durability, int speed, int maxBombCount, int bombPower, Bomber::BombType bombType);
    virtual void update() = 0;
    virtual void onDurabilityLoss() = 0;
    virtual void move(QVector<int> nextPosition) = 0;
    void placeBomb();

    int getBombCount();
    void decrementBombCount();
};

#endif // BOMBER_H
