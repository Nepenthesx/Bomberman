#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Enemy : public Character
{
private:
    QSet<QVector<int>> relativeClosePositions;

public:
    Enemy(QVector<int> position, QVector<int> size, int speed, int durability = 3);

    void update() override;
    void move(QVector<int> nextPosition) override;
    void onDurabilityLoss() override;
};

#endif // ENEMY_H
