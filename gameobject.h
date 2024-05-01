#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QObject>
#include <QList>
#include <QVector>


class GameObject : public QObject
{
    Q_OBJECT

private:


protected:
    QList <GameObject*> objectsInContact;
    int interactPriority;

    QVector<int> position;
    QVector<int> size;
    bool isInteractive;
    int durability;

public:
    GameObject();
    GameObject(QVector<int> position, QVector<int> size);


    void clearObjectsInContact();
    virtual void update() = 0;

    virtual void onDurabilityLoss() = 0;


    //getset
    QVector<int> getPosition();
    void setPosition(int x, int y);
    void setPosition(QVector<int> position);
    QVector<int> getSize();
    void setSize(int x, int y);
    void setSize(QVector<int> size);
    bool getInteractivity();
    void setInteractivity(bool interactivity);
    int getDurability();
    void setDurability(int durability);

};

#endif // GAMEOBJECT_H
