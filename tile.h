#ifndef TILE_H
#define TILE_H

#include "gameobject.h"

#include <QImage>
#include <QPixmap>
#include <QVector>


class Tile : public GameObject
{
protected:

public:
    Tile();

};

class FloorTile : public Tile
{
public:
    FloorTile(QVector<int> position);
    void interact() override;
    void move() override;
    void undoMove() override;
    void onDurabilityLoss() override;

};

class RockTile : public Tile
{
public:
    RockTile(QVector<int> position, int durability = 1);

    void interact() override;
    void move() override;
    void undoMove() override;
    void onDurabilityLoss() override;

};

class WallTile : public Tile
{
public:
    WallTile(QVector<int> position);

    void interact() override;
    void move() override;
    void undoMove() override;
    void onDurabilityLoss() override;
};

#endif // TILE_H
