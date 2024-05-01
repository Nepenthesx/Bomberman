#ifndef BOMB_H
#define BOMB_H

#include "dynamicobject.h"
#include "temporaryobject.h"

class Bomb : public DynamicObject, public TemporaryObject
{
public:enum ExplosionShape
    {
        Cross,
        Square
    };

private:
    ExplosionShape explosionShape;
    //int count;
    //int maxCount; - to cecha gracza, nie bomby
    //int maxCount; //ile może istnieć bomb na raz, powiązać z wartością statyczną - jednak nie, bo wtedy bomby gracza musiałaby być innym obiektem niż bomby przeciwnika
    int explosionPower;

    void explode();

public:
    Bomb(QVector<int> position, QVector<int> size, int durability = 1, int lifetime = 5000, Bomb::ExplosionShape explosionShape = Bomb::Cross);

    void update() override;
    void onDurabilityLoss() override;
    void onTimeout() override;
};

#endif // BOMB_H
