#include "tile.h"

#include "gameobject.h"
#include <QDebug>
#include <QDir>
#include <iostream>
#include <QVector>


Tile::Tile(QVector<int> position, QVector<int> size) : GameObject::GameObject(position, size)
{

}

/// FLOOR TILE

FloorTile::FloorTile(QVector<int> position, QVector<int> size) : Tile::Tile(position, size)
{
    isInteractive = false;
    durability = 0;
}

void FloorTile::update()
{

}

void FloorTile::onDurabilityLoss()
{

}

/*
void FloorTile::interact() {}

void FloorTile::move() {}

void FloorTile::undoMove() {}


*/

/// ROCK TILE

RockTile::RockTile(QVector<int> position, QVector<int> size, int durability) : Tile::Tile(position, size)
{
    interactPriority = 2;

    isInteractive = true;
    this->durability = durability;
}

void RockTile::update()
{

}

/*
void RockTile::interact()
{
    for (GameObject* object : objectsInContact)
    {
        object->undoMove();

        qDebug() << "Collision!";
    }
}
*/

/*
void RockTile::move() {}

void RockTile::undoMove() {}
*/

void RockTile::onDurabilityLoss()
{
    //GameObject* floor = new FloorTile(position);
    delete this;

    //CO Z LISTĄ GAMEOBJECTS???
}

/// WALL TILE

WallTile::WallTile(QVector<int> position, QVector<int> size) : Tile::Tile(position, size)
{
    interactPriority = 2;

    isInteractive = false;
    this->durability = durability;
}

void WallTile::update()
{

}

/*
void WallTile::interact()
{
    for (GameObject* object : objectsInContact)
    {
        object->undoMove();
        qDebug() << "Collision!";
    }
}

void WallTile::move() {}

void WallTile::undoMove() {}
*/

void WallTile::onDurabilityLoss() {}
