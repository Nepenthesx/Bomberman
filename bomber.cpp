#include "bomber.h"
#include "gamemanager.h"

Bomber::Bomber(QVector<int> position, QVector<int> size, int speed, int durability, int maxBombCount, int bombPower, Bomber::BombType bombType)
    : Character(position, size, speed, durability)
{
    setMaxBombCount(maxBombCount);
    setBombPower(bombPower);
    setBombType(bombType);
    bombCount = 0;
}

void Bomber::placeBomb()
{
    if (bombCount < maxBombCount)
    {
        GameManager::createBomb(getPosition(), this, bombPower, bombType);
    }
    else
        qDebug() << "Too much bombs!";

}

int Bomber::getMaxBombCount()
{
    return maxBombCount;
}

void Bomber::setMaxBombCount(int maxBombCount)
{
    if(maxBombCount >= 0)
        this->maxBombCount = maxBombCount;
    else
        this->maxBombCount = 1;
}

int Bomber::getBombPower()
{
    return bombPower;
}

void Bomber::setBombPower(int bombPower)
{
    if (bombPower > 4)
        this->bombPower = 4;
    else if(bombPower >= 0)
        this->bombPower = bombPower;
    else
        this->bombPower = 0;
}

Bomber::BombType Bomber::getBombType()
{
    return bombType;
}

void Bomber::setBombType(Bomber::BombType bombType)
{
    this->bombType = bombType;
}

int Bomber::getBombCount()
{
    return bombCount;
}

void Bomber::incrementBombCount()
{
    bombCount++;
}

void Bomber::decrementBombCount()
{
    if(bombCount > 0)
        bombCount--;
}
