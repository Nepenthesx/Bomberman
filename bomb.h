#ifndef BOMB_H
#define BOMB_H

#include "dynamicobject.h"
#include "temporaryobject.h"
#include "bomber.h"
#include <QSet>

class Bomb : public DynamicObject, public TemporaryObject
{

private:
    Bomber* owner;
    int explosionPower;

    void explode();

protected:
    QSet<QVector<int>> relativeExplosionPositions;

public:
    Bomb(Bomber* owner, QVector<int> position, QVector<int> size, int explosionPower, int lifetime, int durability);

    void update() override;
    void onDurabilityLoss() override;
    void onTimeout() override;
};

#endif // BOMB_H
