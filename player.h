#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
//#include "gamemanager.h"
#include "walltile.h"
#include "rocktile.h"
#include <windows.h> //do wykrywania przycisków

class Player : public Character
{
public:
    //int speed = GameManager::getGlobalScale()
    Player(QVector<int> position, QVector<int> size, int durability = 3, int speed = 10);

    void update() override;
    void move(QVector<int> nextPosition) override;
    void onDurabilityLoss() override;
};

#endif // PLAYER_H
