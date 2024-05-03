#ifndef PLAYER_H
#define PLAYER_H

#include "bomber.h"
//#include "gamemanager.h"
#include "walltile.h"
#include "rocktile.h"
#include <windows.h> //do wykrywania przycisków
#include <QVector>

class Player : public Bomber
{

public:
    //int speed = GameManager::getGlobalScale()
    Player(QVector<int> position, QVector<int> size, int durability = 3, int speed = 32, int maxBombCount = 1, int bombPower = 1, Bomber::BombType bombType = Bomber::Cross);

    void update() override;
    void move(QVector<int> nextPosition) override;
    void onDurabilityLoss() override;

};

#endif // PLAYER_H
