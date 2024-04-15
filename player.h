/*
#ifndef PLAYER_H
#define PLAYER_H

#include "gameobject.h"
#include "tile.h"

#include <QEvent>
#include <QKeyEvent>
#include <Eigen/Dense>


class Player : public GameObject
{
    Q_OBJECT

private:
    Tile* currentTile;
    int speed;

public:
    Player(Vector2i position, Tile* currentTilePointer, GameObject::PivotLocation pivot, int speed, string relativePath, float relativeScale);
    Tile* getCurrentTile();
    void setCurrentTile(Tile* tile);
    void updateCurrentTile();
    int getSpeed();
    void setSpeed(int speedValue);

public slots:
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
};


#endif // PLAYER_H*/
