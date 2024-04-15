#include "character.h"

#include "gameobject.h"
#include <windows.h>
#include <QDebug>
#include <QVector>


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
    setPosition(getPosition()[0] - speed, getPosition()[1]);
}

void Character::moveRight()
{
    setPosition(getPosition()[0] + speed, getPosition()[1]);
}

void Character::moveUp()
{
    setPosition(getPosition()[0], getPosition()[1] - speed);
}

void Character::moveDown()
{
    setPosition(getPosition()[0], getPosition()[1] + speed);
}

Player::Player(QVector<int> position, int speed, int durability)
{
    interactPriority = 2;

    this->position = position;
    setPicture("/img/character.png");
    relativeScale = 1;
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
