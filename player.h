#ifndef PLAYER_H
#define PLAYER_H

#include "bomber.h"
//#include "gamemanager.h"
#include "walltile.h"
#include "rocktile.h"
#include "bombupgrade.h"
#include "powerupgrade.h"
#include <windows.h> //do wykrywania przycisków
#include <QVector>

class Player : public Bomber
{

public:
    //int speed = GameManager::getGlobalScale()
    Player(QVector<int> position, QVector<int> size, int durability = 3, int speed = 32, int maxBombCount = 2, int bombPower = 1, Bomber::BombType bombType = Bomber::Cross);

    void update() override;
    void move(QVector<int> nextPosition) override;
    void onDurabilityLoss() override;

    void pickItem();

};

#endif // PLAYER_H
