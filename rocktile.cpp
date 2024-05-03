#include "rocktile.h"
#include "gamemanager.h"


RockTile::RockTile(QVector<int> position, QVector<int> size, int durability) : DynamicObject::DynamicObject(position, size, durability)
{

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
    GameManager::removeObject(this);
}
