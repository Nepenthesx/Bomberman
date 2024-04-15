#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QObject>
#include <QImage>
#include <QPixmap>
#include <QList>
#include <QVector>


class GameObject : public QObject
{
    Q_OBJECT

protected:
    QList <GameObject*> objectsInContact;
    int interactPriority;

    QVector<int> position;
    QPixmap picture;
    float relativeScale;
    bool isInteractive;
    int durability;

public:
    static int globalScale;
    static int getGlobalScale();
    static void setGlobalScale(int scale);

    void checkContact(GameObject* object);
    void clearObjectsInContact();
    virtual void interact() = 0;
    virtual void move() = 0;
    virtual void undoMove() = 0;
    virtual void onDurabilityLoss() = 0;


    //getset
    QVector<int> getPosition();
    void setPosition(int x, int y);
    void setPosition(QVector<int> position);
    QPixmap getPicture();
    void setPicture(QPixmap pic);
    void setPicture(std::string relativePath);
    float getRelativeScale();
    void setRelativeScale(float relativeScaleValue);
    bool getInteractivity();
    void setInteractivity(bool interactivity);
    int getDurability();
    void setDurability(int durability);



};

#endif // GAMEOBJECT_H
