#include "player.h"
//#include "gamesystem.h"
#include "gameobject.h"
//#include "board.h"
#include "tile.h"

#include <QEvent>
#include <QKeyEvent>
#include <QDebug>
#include <Eigen/Dense>

Player::Player(Vector2i positionVector, GameObject::PivotLocation pivot, int speed, string relativePath, float relativeScale = 1)
{
    setPosition(positionVector(0), positionVector(1));
    setPivotLocation(pivot);
    setSpeed(speed);
    setPicture(relativePath);
    setRelativeScale(relativeScale);
}

/*
void Player::setGameSystem(GameSystem* gameSystemPointer)
{
    gameSystem = gameSystemPointer;
}

void Player::setBoard(Board* boardObject)
{
    board = boardObject;
}
*/

Tile* Player::getCurrentTile()
{
    return currentTile;
}

void Player::updateTile()
{
    //int tileX = position(0)/board->getScale();
    //int tileY = position(0)/board->getScale();
    //currentTile = board->getTile(tileY, tileX);
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
}

void Player::moveRight()
{
    setPosition(getPosition()(0) + getSpeed(), getPosition()(1));
}

void Player::moveUp()
{
    setPosition(getPosition()(0), getPosition()(1) - getSpeed());
}

void Player::moveDown()
{
    setPosition(getPosition()(0), getPosition()(1) + getSpeed());
}
