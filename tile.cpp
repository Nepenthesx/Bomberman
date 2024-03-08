#include "tile.h"

#include <Eigen/Dense>
#include <QImage>
#include <QImageReader>
#include <QPixmap>
#include <QDebug>
#include <QDir>
#include <iostream>

using namespace std;
using namespace Eigen;

Tile::Tile()
{

}

Tile::Tile(string relativePath, bool destructibility, bool permeability, float relativeScale)
{
    setPicture(relativePath);
    setDestructibility(destructibility);
    setPermeability(permeability);
    setRelativeScale(relativeScale);
}

Tile::Tile(Tile* left, Tile* right, Tile* up, Tile* down, bool destructibility, bool permeability)
{
    setLeftTile(left);
    setRightTile(right);
    setUpTile(up);
    setDownTile(down);
    setDestructibility(destructibility);
    setPermeability(permeability);
}

Tile* Tile::getLeftTile()
{
    return leftTile;
}

void Tile::setLeftTile(Tile* tile)
{
    leftTile = tile;
}

Tile* Tile::getRightTile()
{
    return rightTile;
}

void Tile::setRightTile(Tile* tile)
{
    rightTile = tile;
}

Tile* Tile::getUpTile()
{
    return upTile;
}

void Tile::setUpTile(Tile* tile)
{
    upTile = tile;
}

Tile* Tile::getDownTile()
{
    return downTile;
}

void Tile::setDownTile(Tile* tile)
{
    downTile = tile;
}

bool Tile::getDestructibility()
{
    return isDestructible;
}

void Tile::setDestructibility(bool destructibility)
{
    isDestructible = destructibility;
}

bool Tile::getPermeability()
{
    return isPermeable;
}

void Tile::setPermeability(bool permeability)
{
    isPermeable = permeability;
}
