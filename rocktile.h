#ifndef ROCKTILE_H
#define ROCKTILE_H

#include "dynamicobject.h"
#include <QDebug>

class RockTile : public DynamicObject
{
public:
    RockTile(QVector<int> position, QVector<int> size, int durability = 1);

    virtual void update() override;
    virtual void onDurabilityLoss() override;
};

#endif // ROCKTILE_H
