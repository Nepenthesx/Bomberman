#ifndef BOMBTYPEUPGRADE_H
#define BOMBTYPEUPGRADE_H

#include "item.h"

class BombTypeUpgrade : public Item
{
public:
    BombTypeUpgrade(QVector<int> position, QVector<int> size, int lifetime = 8000, int durability = 1);
};

#endif // BOMBTYPEUPGRADE_H
