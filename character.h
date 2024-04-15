#ifndef CHARACTER_H
#define CHARACTER_H

#include <windows.h> //do wykrywania przycisków

#include "gameobject.h"
#include "tile.h"

#include <QEvent>
#include <QKeyEvent>
#include <QVector>


class Character : public GameObject
{
    Q_OBJECT

protected:
    int speed;
    QVector<int> previousPosition;

public:
    int getSpeed();
    void setSpeed(int speed);

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
};

class Player : public Character
{

public:
    Player(QVector<int> position, int speed = GameObject::getGlobalScale() ,int durability = 3);

    void interact() override;
    void move() override;
    void undoMove() override;
    void onDurabilityLoss() override;
};

#endif // CHARACTER_H
