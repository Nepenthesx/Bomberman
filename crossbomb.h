#ifndef CROSSBOMB_H
#define CROSSBOMB_H

#include "bomb.h"

class CrossBomb : public Bomb
{
public:
    CrossBomb(Bomber* owner, QVector<int> position, QVector<int> size, int explosionPower, int lifetime = 4000, int durability = 1);
};

#endif // CROSSBOMB_H
