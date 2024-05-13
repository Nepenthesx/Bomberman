#include "character.h"


Character::Character(QVector<int> position, QVector<int> size, int speed, int durability)
    : DynamicObject::DynamicObject(position, size, durability), MovableObject::MovableObject(speed)
{

}
