#include "item.h"

#include "gameobject.h"

#include <QImage>
#include <QPixmap>
#include <QTimer>
#include <QVector>

int Bomb::count;
int Bomb::maxCount;


void Item::changeTimeoutStatus()
{
    isTimeout = true;
}

Bomb::Bomb(QVector<int> position, int activationTime, Bomb::ExplosionShape explosionShape)
{
    //sprawdź count wszystkich bomb
    if (count <= maxCount)
    {
        interactPriority = 2;

        this->position = position;
        this->explosionShape = explosionShape;
        setPicture("/img/item3.png");
        relativeScale = 1;
        isInteractive = false; //chyba że bombę można kopnąć, ale jak na razie nie ma takiej opcji

        timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(changeTimeoutStatus()));
        timer->setInterval(activationTime);
        timer->start();

        count++;
    }
}

void Bomb::explode()
{
    //wszystkim objectsInContact obniża durability
}

void Bomb::setMaxCount(int count)
{
    if (maxCount > 0)
        maxCount = count;
}

void Bomb::interact()
{
    if (isTimeout)
    {
        explode();

        count--;
    }
}

void Bomb::move() {}

void Bomb::undoMove() {}

void Bomb::onDurabilityLoss() {}

/*
void Bomb::checkContact(GameObject* object)
{
    int myX = position(0);
    int myY = position(1);

    int objectX = object->getPosition()(0);
    int objectY = object->getPosition()(1);

    bool horizontalContact = false;
    bool verticalContact = false;


    int myLeftEdge, myRightEdge, myUpEdge, myDownEdge;

    int objectLeftEdge = objectX;
    int objectRightEdge = objectX + globalScale * object->getRelativeScale();
    int objectUpEdge = objectY;
    int objectDownEdge = objectY + globalScale * object->getRelativeScale();

    switch (explosionShape)
    {
    case Bomb::Cross:
        myLeftEdge = myX - globalScale * relativeScale * explosionPower;
        myRightEdge = myX + globalScale * relativeScale * (1 + explosionPower);
        myUpEdge = myY; //bez zmian
        myDownEdge = myY + globalScale * relativeScale; //bez zmian

        if (myX <= objectX && myRightEdge > objectLeftEdge) //kontakt z prawej
            horizontalContact = true;
        else if (myX >= objectX && myLeftEdge < objectRightEdge) //kontakt z lewej
            horizontalContact = true;

        myLeftEdge = myX; //bez zmian
        myRightEdge = myX + globalScale * relativeScale; //bez zmian
        myUpEdge = myY - globalScale * relativeScale * explosionPower;
        myDownEdge = myY + globalScale * relativeScale * (1 + explosionPower);

        if (myY <= objectY && myDownEdge > objectUpEdge) //kontakt z dołu
            verticalContact = true;
        else if (myY >= objectY && myUpEdge < objectDownEdge) //kontakt z góry
            verticalContact = true;
        break;


    case Bomb::Square:
        myLeftEdge = myX - globalScale * relativeScale * explosionPower;
        myRightEdge = myX + globalScale * relativeScale * (1 + explosionPower);
        myUpEdge = myY - globalScale * relativeScale * explosionPower;
        myDownEdge = myY + globalScale * relativeScale * (1 + explosionPower);

        if (myX <= objectX && myRightEdge > objectLeftEdge) //kontakt z prawej
            horizontalContact = true;
        else if (myX >= objectX && myLeftEdge < objectRightEdge) //kontakt z lewej
            horizontalContact = true;

        if (myY <= objectY && myDownEdge > objectUpEdge) //kontakt z dołu
            verticalContact = true;
        else if (myY >= objectY && myUpEdge < objectDownEdge) //kontakt z góry
            verticalContact = true;
        break;
    }


    if (horizontalContact && verticalContact)
        objectsInContact.push_back(object);
}*/
