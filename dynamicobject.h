#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H

#include "gameobject.h"
#include <QVector>

class DynamicObject : public GameObject
{
protected:
    int durability;

    int getDurability();
    void setDurability(int durability);

public:
    DynamicObject(QVector<int> position, QVector<int> size, int durability);
    virtual void update() = 0;
    virtual void onDurabilityLoss() = 0;
    void takeDamage(int damage);
};

#endif // DYNAMICOBJECT_H
