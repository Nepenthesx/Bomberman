/*
#include "player.h"
#include "gameobject.h"
#include "tile.h"

#include <QEvent>
#include <QKeyEvent>
#include <QDebug>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;


Player::Player(Vector2i positionVector, Tile* currentTilePointer, GameObject::PivotLocation pivot, int speed, string relativePath, float relativeScale = 1)
{
    setPosition(positionVector(0), positionVector(1));
    setCurrentTile(currentTilePointer);
    setPivotLocation(pivot);
    setSpeed(speed);
    setPicture(relativePath);
    setRelativeScale(relativeScale);
}

Tile* Player::getCurrentTile()
{
    return currentTile;
}

void Player::setCurrentTile(Tile *tile)
{
    currentTile = tile;
}

int GameObject::globalScale;

void Player::updateCurrentTile()
{
    int tileX = getCurrentTile()->getPosition()(0);
    int tileY = getCurrentTile()->getPosition()(1);

    int x = getPosition()(0);
    int y = getPosition()(1);

    if (x > tileX + getCurrentTile()->getRelativeScale() * globalScale / 2)
    {
        setCurrentTile(getCurrentTile()->getRightTile());
    }
    if (x < tileX - getCurrentTile()->getRelativeScale() * globalScale / 2)
    {
        setCurrentTile(getCurrentTile()->getLeftTile());
    }
    if (y > tileY + getCurrentTile()->getRelativeScale() * globalScale / 2)
    {
        setCurrentTile(getCurrentTile()->getDownTile());
    }
    if (y < tileY - getCurrentTile()->getRelativeScale() * globalScale / 2)
    {
        setCurrentTile(getCurrentTile()->getUpTile());
    }

    qDebug() << currentTile->number;
}

int Player::getSpeed()
{
    return speed;
}

void Player::setSpeed(int speedValue)
{
    speed = speedValue;
}

void Player::moveLeft()
{
    setPosition(getPosition()(0) - getSpeed(), getPosition()(1));
    updateCurrentTile();

    if (currentTile == nullptr || !currentTile->getPermeability())
        setPosition(getPosition()(0) + getSpeed(), getPosition()(1));

    updateCurrentTile();
}

void Player::moveRight()
{
    setPosition(getPosition()(0) + getSpeed(), getPosition()(1));
    updateCurrentTile();

    if (currentTile == nullptr || !currentTile->getPermeability())
        setPosition(getPosition()(0) - getSpeed(), getPosition()(1));

    updateCurrentTile();
}

void Player::moveUp()
{
    setPosition(getPosition()(0), getPosition()(1) - getSpeed());
    updateCurrentTile();

    if (currentTile == nullptr || !currentTile->getPermeability())
        setPosition(getPosition()(0), getPosition()(1) + getSpeed());

    updateCurrentTile();
}

void Player::moveDown()
{
    setPosition(getPosition()(0), getPosition()(1) + getSpeed());
    updateCurrentTile();

    if (currentTile == nullptr || !currentTile->getPermeability())
        setPosition(getPosition()(0), getPosition()(1) - getSpeed());

    updateCurrentTile();
}*/
