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

private:
    int bombCount;
    int maxBombCount;
    int bombPower;
    Bomber::BombType bombType;

protected:
    int getMaxBombCount();
    void setMaxBombCount(int maxBombCount);
    int getBombPower();
    void setBombPower(int bombPower);
    Bomber::BombType getBombType();
    void setBombType(Bomber::BombType bombType);

public:
    Bomber(QVector<int> position, QVector<int> size, int speed, int durability, int maxBombCount, int bombPower, Bomber::BombType bombType);
    virtual void update() = 0;
    virtual void onDurabilityLoss() = 0;
    virtual void move(QVector<int> nextPosition) = 0;
    void placeBomb();

    int getBombCount();
    void incrementBombCount();
    void decrementBombCount();
};

#endif // BOMBER_H
