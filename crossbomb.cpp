#include "crossbomb.h"

CrossBomb::CrossBomb(Bomber* owner, QVector<int> position, QVector<int> size, int explosionPower, int lifetime, int durability)
    : Bomb(owner, position, size, explosionPower, lifetime, durability)
{
    for (int i = 0; i <= explosionPower; i++)
    {
        relativeExplosionPositions.insert(QVector<int>({i, 0}));
        relativeExplosionPositions.insert(QVector<int>({0, i}));
        relativeExplosionPositions.insert(QVector<int>({-i, 0}));
        relativeExplosionPositions.insert(QVector<int>({0, -i}));
    }
}
