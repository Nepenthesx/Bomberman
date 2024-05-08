#ifndef SQUAREBOMB_H
#define SQUAREBOMB_H

#include "bomb.h"

class SquareBomb : public Bomb
{
public:
    SquareBomb(Bomber* owner, QVector<int> position, QVector<int> size, int explosionPower, int lifetime = 4000, int durability = 1);
};

#endif // SQUAREBOMB_H
