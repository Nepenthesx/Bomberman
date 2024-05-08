#ifndef BOMBPOWERUPGRADE_H
#define BOMBPOWERUPGRADE_H

#include "item.h"

class BombPowerUpgrade : public Item
{
public:
    BombPowerUpgrade(QVector<int> position, QVector<int> size, int lifetime = 8000, int durability = 1);
};

#endif // BOMBPOWERUPGRADE_H
