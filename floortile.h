#ifndef FLOORTILE_H
#define FLOORTILE_H

#include "staticobject.h"

class FloorTile : public StaticObject
{
public:
    FloorTile(QVector<int> position, QVector<int> size);
    void update() override;
};

#endif // FLOORTILE_H
