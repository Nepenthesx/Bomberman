#include "bomb.h"
#include "gamemanager.h"
#include <typeinfo>


Bomb::Bomb(Bomber* owner, QVector<int> position, QVector<int> size, int explosionPower, int lifetime, int durability) : DynamicObject(position, size, durability), TemporaryObject(lifetime)
{
    //może set?
    this->owner = owner;
    this->explosionPower = explosionPower;
}

void Bomb::update()
{
    if (isTimeout)
        onTimeout();
    if (getDurability() <= 0)
        onDurabilityLoss();
}

void Bomb::onDurabilityLoss()
{
    qDebug() << "Explode!";
    explode();
    owner->decrementBombCount();
    GameManager::removeObject(this);
}

void Bomb::onTimeout()
{
    takeDamage(1);
}

void Bomb::explode()
{
    QSet objectsInContact(GameManager::getObjectsInContactArea(getPosition(), relativeExplosionPositions, getSize()));
    qDebug() << objectsInContact.count();

    // for(QSet<GameObject*>::iterator it = objectsInContact.begin(); it != objectsInContact.end() ; it++)
    for (GameObject* object : objectsInContact)
    {
        if (DynamicObject* dynamicObject = dynamic_cast<DynamicObject*>(object))
        {
            if (dynamicObject != this)
            {
                dynamicObject->takeDamage(1);
                qDebug() << "Damaged!";
            }
        }
    }


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
