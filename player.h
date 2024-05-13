#ifndef PLAYER_H
#define PLAYER_H

#include "bomber.h"
#include <windows.h> //do wykrywania przycisków
#include <QVector>

class Player : public Bomber
{

public:
    Player(QVector<int> position, QVector<int> size, int speed, int durability = 3, int maxBombCount = 1, int bombPower = 1, Bomber::BombType bombType = Bomber::Cross);

    void update() override;
    void move(QVector<int> nextPosition) override;
    void onDurabilityLoss() override;

    void pickItem();

};

#endif // PLAYER_H
