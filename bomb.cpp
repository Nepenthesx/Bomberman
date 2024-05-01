#include "bomb.h"


Bomb::Bomb(QVector<int> position, QVector<int> size, int durability, int lifetime, Bomb::ExplosionShape explosionShape) : DynamicObject(position, size, durability), TemporaryObject(lifetime)
{
    //może set?
    this->explosionShape = explosionShape;
}

void Bomb::update()
{
    if (isTimeout)
        onTimeout();
}

void Bomb::onDurabilityLoss()
{
    explode();
    delete this;
}

void Bomb::onTimeout()
{
    takeDamage(1);
}

void Bomb::explode()
{
    /* POWIĄZAĆ Z GAMEMANAGER::CHECK CONTACT
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
    */
    //ZNALEŹĆ LISTĘ OBIEKTÓW W KONTAKCIE (TEŻ W ZALEŻNOŚCI OD KLASY) I WYWOŁAĆ U NICH TAKEDAMAGE
}
