#include "rocktile.h"

#include "gamemanager.h"
#include <stdlib.h>


RockTile::RockTile(QVector<int> position, QVector<int> size, int durability) : DynamicObject::DynamicObject(position, size, durability)
{
    srand(0);
}

void RockTile::update()
{
    if (getDurability() <= 0)
        onDurabilityLoss();
}

void RockTile::onDurabilityLoss()
{
    qDebug() << "Destroyed!";
    GameManager::createFloor(getPosition());

    int num = rand() % 2 + 1;
    qDebug() << num;
    if(num == 1)
        GameManager::createBombUpgrade(getPosition());
    else if (num == 2)
        GameManager::createPowerUpgrade(getPosition());

    GameManager::removeObject(this);
}
