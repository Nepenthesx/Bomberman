#include "bomber.h"
#include "gamemanager.h"

Bomber::Bomber(QVector<int> position, QVector<int> size, int durability, int speed, int maxBombCount, int bombPower, Bomber::BombType bombType) : Character(position, size, durability, speed)
{
    setMaxBombCount(maxBombCount);
    setBombPower(bombPower);
    setBombType(bombType);
}

void Bomber::placeBomb()
{
    if (bombCount < maxBombCount)
    {
        GameManager::createBomb(this, getPosition(), bombPower, bombType);
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
    if (bombPower > 3)
        this->bombPower = 3;
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

void Bomber::setBombCount(int bombCount)
{
    if(bombCount >= 0)
        this->bombCount = bombCount;
}
//lub
void Bomber::decrementBombCount()
{
    if(bombCount > 0)
        bombCount--;
}
