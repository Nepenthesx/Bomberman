#ifndef WALLTILE_H
#define WALLTILE_H

#include "staticobject.h"

class WallTile : public StaticObject
{
public:
    WallTile(QVector<int> position, QVector<int> size);
    void update() override;
};

#endif // WALLTILE_H
