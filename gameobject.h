#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QObject>
#include <QList>
#include <QVector>
#include <QDebug>

class GameObject
{
private:

protected:
    QVector<int> position;
    QVector<int> size;

public:
    GameObject(QVector<int> position, QVector<int> size);
    virtual ~GameObject() {qDebug() << "Destroyed!";}

    virtual void update() = 0;

    //getset
    QVector<int> getPosition();
    void setPosition(int x, int y);
    void setPosition(QVector<int> position);
    QVector<int> getSize();
    void setSize(int x, int y);
    void setSize(QVector<int> size);

};

#endif // GAMEOBJECT_H
