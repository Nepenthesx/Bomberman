#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QVector>
#include <QDebug>

class GameObject
{
private:

protected:
    QVector<int> position;
    QVector<int> size;
    bool isActive = true;

public:
    GameObject(QVector<int> position, QVector<int> size);
    virtual ~GameObject();

    virtual void update() = 0;

    QVector<int> getPosition();
    void setPosition(QVector<int> position);
    QVector<int> getSize();
    void setSize(QVector<int> size);
    bool checkActivity();
    void desactive();

};

#endif // GAMEOBJECT_H
