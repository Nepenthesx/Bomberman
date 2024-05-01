#ifndef TILE_H
#define TILE_H

#include "gameobject.h"

#include <QVector>


class Tile : public GameObject
{
protected:

public:
    Tile(QVector<int> position, QVector<int> size);
    virtual void update() = 0;

};

class FloorTile : public Tile
{
public:
    FloorTile(QVector<int> position, QVector<int> size);
    void update() override;
    void onDurabilityLoss() override;

};

class RockTile : public Tile
{
public:
    RockTile(QVector<int> position, QVector<int> size, int durability = 1);

    void update() override;
    void onDurabilityLoss() override;

};

class WallTile : public Tile
{
public:
    WallTile(QVector<int> position, QVector<int> size);

    void update() override;
    void onDurabilityLoss() override;
};

#endif // TILE_H
