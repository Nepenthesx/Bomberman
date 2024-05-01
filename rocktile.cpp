#include "rocktile.h"


RockTile::RockTile(QVector<int> position, QVector<int> size, int durability) : DynamicObject::DynamicObject(position, size, durability)
{

}

void RockTile::update()
{

}

void RockTile::onDurabilityLoss()
{
    //GameObject* floor = new FloorTile(position);
    delete this;

    //CO Z LISTĄ GAMEOBJECTS???
}
