#include "character.h"

#include "gameobject.h"
#include "tile.h"
#include <windows.h>
#include <QDebug>
#include <QVector>


Character::Character(QVector<int> position, QVector<int> size) : GameObject::GameObject(position, size)
{

}

int Character::getSpeed()
{
    return speed;
}

void Character::setSpeed(int speed)
{
    if (speed > 0)
        this->speed = speed;
}

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

void Character::moveRight()
{
    setPosition(position[0] + speed, position[1]);
}

void Character::moveUp()
{
    setPosition(position[0], position[1] - speed);
}

void Character::moveDown()
{
    setPosition(position[0], position[1] + speed);
}

Player::Player(QVector<int> position, QVector<int> size, int speed, int durability) : Character(position, size)
{
    interactPriority = 2;

    isInteractive = true;
    this->durability = durability;
    this->speed = speed;
}

void Player::update()
{
    QList<GameObject*> objectsInRange(GameManager::getObjectsInRange(this, speed).count());

    if (GetAsyncKeyState(VK_LEFT))
    {
        qDebug() << "Left";
        move(QVector<int>({position[0] - speed, position[1]}));
        //moveLeft();
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        qDebug() << "Right";
        move(QVector<int>({position[0] + speed, position[1]}));
        //moveRight();
    }
    if (GetAsyncKeyState(VK_UP))
    {
        qDebug() << "Up";
        move(QVector<int>({position[0], position[1] - speed}));
        //moveUp();
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        qDebug() << "Down";
        move(QVector<int>({position[0], position[1] + speed}));
        //moveDown();
    }
}

/*
void Player::interact()
{

}
*/

void Player::move(QVector<int> nextPosition)
{
    //previousPosition = position;

    QList<GameObject*> objectsInContact(GameManager::getObjectsInContact(nextPosition, size));
    for (GameObject* object : objectsInContact)
    {
        if(dynamic_cast<WallTile*>(object) || dynamic_cast<RockTile*>(object) || dynamic_cast<Character*>(object))
        {
            qDebug() << "Collision!";
            return;
        }
    }

    //kolizja nie wystąpiła - zrób ruch
    setPosition(nextPosition);



    //qDebug() << GameManager::getObjectsInRange(this, speed).count();
}

/*
void Player::undoMove()
{
    position = previousPosition;
}
*/

void Player::onDurabilityLoss()
{
    qDebug() << "Game Over!";
    delete this;
}
