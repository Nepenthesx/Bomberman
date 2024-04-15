#include "tile.h"

#include <QImage>
#include <QImageReader>
#include <QPixmap>
#include <QDebug>
#include <QDir>
#include <iostream>
#include <QVector>


Tile::Tile()
{

}

/// FLOOR TILE

FloorTile::FloorTile(QVector<int> position)
{
    this->position = position;
    setPicture("/img/tile1.png");
    relativeScale = 1;
    isInteractive = false;
    durability = 0;
}

void FloorTile::interact() {}

void FloorTile::move() {}

void FloorTile::undoMove() {}

void FloorTile::onDurabilityLoss() {}

/// ROCK TILE

RockTile::RockTile(QVector<int> position, int durability)
{
    interactPriority = 2;

    this->position = position;
    setPicture("/img/tile2.png");
    relativeScale = 1;
    isInteractive = true;
    this->durability = durability;
}

void RockTile::interact()
{
    for (GameObject* object : objectsInContact)
    {
        object->undoMove();

        qDebug() << "Collision!";
    }
}

void RockTile::move() {}

void RockTile::undoMove() {}

void RockTile::onDurabilityLoss()
{
    GameObject* floor = new FloorTile(position);
    delete this;

    //CO Z LISTĄ GAMEOBJECTS???
}

/// WALL TILE

WallTile::WallTile(QVector<int> position)
{
    interactPriority = 2;

    this->position = position;
    setPicture("/img/tile3.png");
    relativeScale = 1;
    isInteractive = false;
    this->durability = durability;
}

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

void WallTile::onDurabilityLoss() {}
