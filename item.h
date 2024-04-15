#ifndef ITEM_H
#define ITEM_H

#include "gameobject.h"

#include <QImage>
#include <QPixmap>
#include <QTimer>
#include <QVector>


class Item : public GameObject
{

protected:
    QTimer* timer;
    bool isTimeout = false;

public slots:
    void changeTimeoutStatus();

};

class Bomb : public Item
{

public:enum ExplosionShape
    {
        Cross,
        Square
    };

private:
    ExplosionShape explosionShape;
    int explosionPower;
    //int maxCount; //ile może istnieć bomb na raz, powiązać z wartością statyczną

    void explode();


public:
    static int count;
    static int maxCount;

    Bomb(QVector<int> position, int activationTime, ExplosionShape explosionShape);
    static void setMaxCount(int count);

    void interact() override;
    void move() override;
    void undoMove() override;
    void onDurabilityLoss() override;

    //void checkContact(GameObject* object) override; //bardzo ważne! nadpisuje zwyczajne sprawdzanie kontaktu po pokryciu kafelków

};

#endif // ITEM_H
