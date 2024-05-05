#ifndef BOMBUPGRADE_H
#define BOMBUPGRADE_H

#include "item.h"

class BombUpgrade : public Item
{
public:
    BombUpgrade(QVector<int> position, QVector<int> size, int lifetime = 7000, int durability = 1);
};

#endif // BOMBUPGRADE_H
