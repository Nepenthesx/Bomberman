#include "gameobject.h"


GameObject::GameObject(QVector<int> position, QVector<int> size)
{
    setPosition(position);
    setSize(size);
    isActive = true;
}

GameObject::~GameObject()
{
    qDebug() << "Destroyed!";
}

QVector<int> GameObject::getPosition()
{
    return position;
}

void GameObject::setPosition(QVector<int> position)
{
    if (position[0] >= 0 && position[1] >= 0)
    {
        this->position = position;
    }
}

QVector<int> GameObject::getSize()
{
    return size;
}

void GameObject::setSize(QVector<int> size)
{
    if (size[0] >= 0 && size[1] >= 0)
    {
        this->size = size;
    }
}

bool GameObject::checkActivity()
{
    return isActive;
}

void GameObject::desactive()
{
    isActive = false;
}
