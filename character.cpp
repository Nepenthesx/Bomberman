#include "character.h"

#include "gameobject.h"
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

void Player::interact()
{

}

void Player::move()
{
    previousPosition = position;

    if (GetAsyncKeyState(VK_LEFT))
    {
        qDebug() << "Left";
        moveLeft();
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        qDebug() << "Right";
        moveRight();
    }
    if (GetAsyncKeyState(VK_UP))
    {
        qDebug() << "Up";
        moveUp();
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        qDebug() << "Down";
        moveDown();
    }
}

void Player::undoMove()
{
    position = previousPosition;
}

void Player::onDurabilityLoss()
{
    qDebug() << "Game Over!";
    delete this;
}
