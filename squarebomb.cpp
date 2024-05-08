#include "squarebomb.h"

SquareBomb::SquareBomb(Bomber* owner, QVector<int> position, QVector<int> size, int explosionPower, int lifetime, int durability)
    : Bomb(owner, position, size, explosionPower, lifetime, durability)
{

    for (int i = -explosionPower; i <= explosionPower; i++)
    {
        for (int j = -explosionPower; j <= explosionPower; j++)
        {
            relativeExplosionPositions.insert(QVector<int>({i, j}));
        }
    }

    /*
    switch (explosionPower)
    {
    case 0:
        relativeExplosionPositions = QSet<QVector<int>> {
            QVector<int>({0, 0}),
        };
        break;
    case 1:
        relativeExplosionPositions = QSet<QVector<int>> {
            QVector<int>({-1, -1}),
            QVector<int>({-1, 0}),
            QVector<int>({0, -1}),
            QVector<int>({0, 0}),
            QVector<int>({0, 1}),
            QVector<int>({1, 0}),
            QVector<int>({1, 1}),
            QVector<int>({-1, 1}),
            QVector<int>({1, -1})
        };
        break;
    case 2:
        relativeExplosionPositions = QSet<QVector<int>> {
            QVector<int>({-2, -2}),
            QVector<int>({-2, -1}),
            QVector<int>({-1, -2}),
            QVector<int>({-2, 0}),
            QVector<int>({0, -2}),

            QVector<int>({-1, -1}),
            QVector<int>({-1, 0}),
            QVector<int>({0, -1}),
            QVector<int>({0, 0}),
            QVector<int>({0, 1}),
            QVector<int>({1, 0}),
            QVector<int>({1, 1}),
            QVector<int>({-1, 1}),
            QVector<int>({1, -1}),

            QVector<int>({2, 2}),
            QVector<int>({2, 1}),
            QVector<int>({1, 2}),
            QVector<int>({2, 0}),
            QVector<int>({0, 2}),

            QVector<int>({-2, 2}),
            QVector<int>({2, -2}),
            QVector<int>({-2, 1}),
            QVector<int>({1, -2}),
            QVector<int>({2, -1}),
            QVector<int>({-1, 2})
        };
        break;
    case 3:
        //ZMIENIC NA 3
        relativeExplosionPositions = QSet<QVector<int>> {
            QVector<int>({-2, -2}),
            QVector<int>({-2, -1}),
            QVector<int>({-1, -2}),
            QVector<int>({-2, 0}),
            QVector<int>({0, -2}),

            QVector<int>({-1, -1}),
            QVector<int>({-1, 0}),
            QVector<int>({0, -1}),
            QVector<int>({0, 0}),
            QVector<int>({0, 1}),
            QVector<int>({1, 0}),
            QVector<int>({1, 1}),
            QVector<int>({-1, 1}),
            QVector<int>({1, -1}),

            QVector<int>({2, 2}),
            QVector<int>({2, 1}),
            QVector<int>({1, 2}),
            QVector<int>({2, 0}),
            QVector<int>({0, 2}),

            QVector<int>({-2, 2}),
            QVector<int>({2, -2}),
            QVector<int>({-2, 1}),
            QVector<int>({1, -2}),
            QVector<int>({2, -1}),
            QVector<int>({-1, 2})
        };
        break;
    default:
        relativeExplosionPositions = QSet<QVector<int>> {
            QVector<int>({0, 0}),
        };
    }*/
}
