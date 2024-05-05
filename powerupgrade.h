#ifndef POWERUPGRADE_H
#define POWERUPGRADE_H

#include "item.h"

class PowerUpgrade : public Item
{
public:
    PowerUpgrade(QVector<int> position, QVector<int> size, int lifetime = 6000, int durability = 1);
};

#endif // POWERUPGRADE_H
