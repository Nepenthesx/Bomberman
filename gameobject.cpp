#include "gameobject.h"

#include <QImage>
#include <QImageReader>
#include <QPixmap>
#include <QDebug>
#include <QDir>
#include <iostream>
#include <QVector>


int GameObject::globalScale;


int GameObject::getGlobalScale()
{
    return globalScale;
}

void GameObject::setGlobalScale(int scale)
{
    if (scale > 0)
        globalScale = scale;
    else
        globalScale = 32;
}

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
    qDebug() << position[0];
    this->position = position;
}

QPixmap GameObject::getPicture()
{
    return picture;
}

void GameObject::setPicture(QPixmap pic)
{
    picture = pic;
}

void GameObject::setPicture(std::string relativePath)
{
    QDir dir(QDir::currentPath());
    std::string spath = "../PJC" + relativePath;
    QString qpath = QString::fromStdString(spath);
    qpath = dir.absoluteFilePath(qpath);

    QImageReader reader(qpath);
    reader.setDecideFormatFromContent(true);

    QImage img = reader.read();
    if (!img.isNull())
        picture = QPixmap::fromImage(img);
    else
        qDebug() << "Error to load file";
}

/*
int GameObject::getGlobalScale()
{
    return globalScale;
}

void GameObject::setGlobalScale(int scale)
{
    globalScale = scale;
}
*/

float GameObject::getRelativeScale()
{
    return relativeScale;
}

void GameObject::setRelativeScale(float relativeScaleValue)
{
    relativeScale = relativeScaleValue;
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

/*
GameObject::PivotLocation GameObject::getPivotLocation()
{
    return pivotLocation;
}

void GameObject::setPivotLocation(GameObject::PivotLocation pivot)
{
    pivotLocation = pivot;
}
*/
