#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "gameobject.h"
#include <QVector>

class StaticObject : public GameObject
{
public:
    StaticObject(QVector<int> position, QVector<int> size);
    virtual void update() = 0;
};

#endif // STATICOBJECT_H
