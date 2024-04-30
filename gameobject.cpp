#include "gameobject.h"

#include <QDebug>
#include <QDir>
#include <iostream>
#include <QVector>


GameObject::GameObject()
{

}

GameObject::GameObject(QVector<int> position, QVector<int> size)
{
    this->position = position;
    this->size = size;
}

/*
void GameObject::checkContact(GameObject* object)
{
    int myX = position[0];
    int myY = position[1];

    int objectX = object->getPosition()[0];
    int objectY = object->getPosition()[1];

    int myLeftEdge = myX;
    int myRightEdge = myX + globalScale * relativeScale;
    int myUpEdge = myY;
    int myDownEdge = myY + globalScale * relativeScale;

    int objectLeftEdge = objectX;
    int objectRightEdge = objectX + globalScale * object->getRelativeScale();
    int objectUpEdge = objectY;
    int objectDownEdge = objectY + globalScale * object->getRelativeScale();

    bool horizontalContact = false;
    bool verticalContact = false;

    if (myX <= objectX && myRightEdge > objectLeftEdge) //kontakt z prawej
        horizontalContact = true;
    else if (myX >= objectX && myLeftEdge < objectRightEdge) //kontakt z lewej
        horizontalContact = true;

    if (myY <= objectY && myDownEdge > objectUpEdge) //kontakt z dołu
        verticalContact = true;
    else if (myY >= objectY && myUpEdge < objectDownEdge) //kontakt z góry
        verticalContact = true;

    if (horizontalContact && verticalContact)
        objectsInContact.push_back(object);
}


void GameObject::clearObjectsInContact()
{
    objectsInContact.clear();
}
*/

QVector<int> GameObject::getPosition()
{
    return position;
}

void GameObject::setPosition(int x, int y)
{
    QVector<int> pos({x, y}); //wykazuje bledy
    position = pos;
}

void GameObject::setPosition(QVector<int> position)
{
    this->position = position;
}

QVector<int> GameObject::getSize()
{
    return size;
}

void GameObject::setSize(int x, int y)
{
    QVector<int> size({x, y});
    this->size = size;
}
void GameObject::setSize(QVector<int> size)
{
    this->size = size;
}

bool GameObject::getInteractivity()
{
    return isInteractive;
}

void GameObject::setInteractivity(bool interactivity)
{
    isInteractive = interactivity;
}

int GameObject::getDurability()
{
    return durability;
}

void GameObject::setDurability(int durability)
{
    if (durability >= 0)
        this->durability = durability;
}
