#include "rocktile.h"

#include "gamemanager.h"
#include <stdlib.h>


RockTile::RockTile(QVector<int> position, QVector<int> size, int durability)
    : DynamicObject::DynamicObject(position, size, durability)
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
    GameManager::createFloorTile(getPosition());

    int num = rand() % 10 + 1;

    if(num == 1)
        GameManager::createBombTypeUpgrade(getPosition());
    else if (num == 2)
        GameManager::createBombPowerUpgrade(getPosition());
    else if (num == 3)
        GameManager::createBombCountUpgrade(getPosition());

    desactive();
}
