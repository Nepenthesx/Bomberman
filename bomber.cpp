#include "bomber.h"
#include "gamemanager.h"

Bomber::Bomber(QVector<int> position, QVector<int> size, int durability, int speed, int maxBombCount, int bombPower, Bomber::BombType bombType)
    : Character(position, size, durability, speed)
{
    setMaxBombCount(maxBombCount);
    setBombPower(bombPower);
    setBombType(bombType);
}

void Bomber::placeBomb()
{
    if (bombCount < maxBombCount)
    {
        GameManager::createBomb(getPosition(), this, bombPower, bombType);
        bombCount++;
    }
    else
        qDebug() << "Too much bombs!";

}

void Bomber::setMaxBombCount(int maxBombCount)
{
    if(maxBombCount >= 0)
        this->maxBombCount = maxBombCount;
    else
        this->maxBombCount = 1;
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

void Bomber::setBombType(Bomber::BombType bombType)
{
    this->bombType = bombType;
}

int Bomber::getBombCount()
{
    return bombCount;
}

void Bomber::decrementBombCount()
{
    if(bombCount > 0)
        bombCount--;
}
