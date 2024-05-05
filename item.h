#ifndef ITEM_H
#define ITEM_H

#include "dynamicobject.h"
#include "temporaryobject.h"

class Item : public DynamicObject, public TemporaryObject
{
public:
    Item(QVector<int> position, QVector<int> size, int lifetime, int durability);

    void update() override;
    void onDurabilityLoss() override;
    void onTimeout() override;
};

#endif // ITEM_H
