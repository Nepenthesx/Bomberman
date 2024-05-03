#include "crossbomb.h"

CrossBomb::CrossBomb(Bomber* owner, QVector<int> position, QVector<int> size, int explosionPower, int lifetime, int durability)
    : Bomb(owner, position, size, explosionPower, lifetime, durability)
{
    qDebug() << "Cross";

    switch (explosionPower)
    {
    case 0:
        relativeExplosionPositions = QSet<QVector<int>> {
            QVector<int>({0, 0}),
        };
        break;
    case 1:
        relativeExplosionPositions = QSet<QVector<int>> {
            QVector<int>({-1, 0}),
            QVector<int>({0, -1}),
            QVector<int>({0, 0}),
            QVector<int>({0, 1}),
            QVector<int>({1, 0})
        };
        break;
    case 2:
        relativeExplosionPositions = QSet<QVector<int>> {
            QVector<int>({-2, 0}),
            QVector<int>({0, -2}),
            QVector<int>({-1, 0}),
            QVector<int>({0, -1}),
            QVector<int>({0, 0}),
            QVector<int>({0, 1}),
            QVector<int>({1, 0}),
            QVector<int>({2, 0}),
            QVector<int>({0, 2})
        };
       break;
    case 3:
        relativeExplosionPositions = QSet<QVector<int>> {
            QVector<int>({-3, 0}),
            QVector<int>({0, -3}),
            QVector<int>({-2, 0}),
            QVector<int>({0, -2}),
            QVector<int>({-1, 0}),
            QVector<int>({0, -1}),
            QVector<int>({0, 0}),
            QVector<int>({0, 1}),
            QVector<int>({1, 0}),
            QVector<int>({2, 0}),
            QVector<int>({0, 2}),
            QVector<int>({3, 0}),
            QVector<int>({0, 3})
        };
        break;
    default:
        relativeExplosionPositions = QSet<QVector<int>> {
            QVector<int>({0, 0}),
            };
    }

}
