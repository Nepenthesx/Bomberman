#include "gameobject.h"


GameObject::GameObject(QVector<int> position, QVector<int> size)
{
    setPosition(position);
    setSize(size);
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
