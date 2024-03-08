#ifndef PLAYER_H
#define PLAYER_H

#include "gameobject.h"
//#include "board.h"
#include "tile.h"

#include <QEvent>
#include <QKeyEvent>
#include <Eigen/Dense>

class Player : public GameObject
{
    Q_OBJECT

private:
    //GameSystem* gameSystem;
    //Board* board;
    Tile* currentTile;
    int speed;

public:
    Player(Vector2i positionVector, GameObject::PivotLocation pivot, int speed, string relativePath, float relativeScale);
    //void setGameSystem(GameSystem* gameSystemPointer);
    //void setBoard(Board* boardObject);
    Tile* getCurrentTile();
    void updateTile();
    int getSpeed();
    void setSpeed(int speedValue);

public slots:
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
};

#endif // PLAYER_H
