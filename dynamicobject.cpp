#include "dynamicobject.h"


DynamicObject::DynamicObject(QVector<int> position, QVector<int> size, int durability)
    : GameObject::GameObject(position, size)
{
    setDurability(durability);
}

void DynamicObject::takeDamage(int damage)
{
    setDurability(getDurability() - damage);
}

int DynamicObject::getDurability()
{
    return durability;
}

void DynamicObject::setDurability(int durability)
{
    if (durability >= 0)
        this->durability = durability;
    else
        this->durability = 0;
}
