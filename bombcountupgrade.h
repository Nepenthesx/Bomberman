#ifndef BOMBCOUNTUPGRADE_H
#define BOMBCOUNTUPGRADE_H

#include "item.h"

class BombCountUpgrade : public Item
{
public:
    BombCountUpgrade(QVector<int> position, QVector<int> size, int lifetime = 8000, int durability = 1);
};

#endif // BOMBCOUNTUPGRADE_H
