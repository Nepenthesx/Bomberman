#include "bomb.h"
#include "gamemanager.h"
#include <typeinfo>


Bomb::Bomb(Bomber* owner, QVector<int> position, QVector<int> size, int explosionPower, int lifetime, int durability)
    : DynamicObject(position, size, durability), TemporaryObject(lifetime)
{
    //może set?
    this->owner = owner;
    this->explosionPower = explosionPower;
    owner->incrementBombCount();
}

void Bomb::update()
{
    if (checkTimeout())
        onTimeout();
    if (getDurability() <= 0)
        onDurabilityLoss();
}

void Bomb::onDurabilityLoss()
{
    qDebug() << "Explode!";
    explode();
    owner->decrementBombCount();
    desactive();
}

void Bomb::onTimeout()
{
    takeDamage(1);
}

void Bomb::explode()
{
    QSet objectsInContact(GameManager::getObjectsInContactArea(getPosition(), relativeExplosionPositions, getSize()));

    // for(QSet<GameObject*>::iterator it = objectsInContact.begin(); it != objectsInContact.end() ; it++)
    for (GameObject* object : objectsInContact)
    {
        if (DynamicObject* dynamicObject = dynamic_cast<DynamicObject*>(object))
        {
            if (dynamicObject != this)
            {
                dynamicObject->takeDamage(1);
                qDebug() << "Damaged!";
            }
        }
    }
}
