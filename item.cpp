#include "item.h"

#include "gamemanager.h"

Item::Item(QVector<int> position, QVector<int> size, int lifetime, int durability)
    : DynamicObject(position, size, durability), TemporaryObject(lifetime)
{

}

void Item::update()
{
    if (isTimeout)
        onTimeout();
    if (getDurability() <= 0)
        onDurabilityLoss();
}

void Item::onDurabilityLoss()
{
    desactive();
}

void Item::onTimeout()
{
    takeDamage(1);
}
