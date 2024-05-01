#include "character.h"


Character::Character(QVector<int> position, QVector<int> size, int durability, int speed) : DynamicObject::DynamicObject(position, size, durability), MovableObject::MovableObject(speed)
{

}

/*
void Character::moveLeft()
{
    QVector<int> nextPosition(position[0] - speed, position[1]);
    QList<GameObject*> objectsInContact(GameManager::getObjectsInContact(nextPosition, size));
    for (GameObject* object : objectsInContact)
    {
        if(dynamic_cast<WallTile*>(object) || dynamic_cast<RockTile*>(object))
        {
            qDebug() << "Collision!";
            return;
        }
    }

    //kolizja nie wystąpiła - zrób ruch
    setPosition(position[0] - speed, position[1]);
}
*/

