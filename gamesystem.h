/*
#ifndef GAMESYSTEM_H
#define GAMESYSTEM_H

#include "board.h"
#include "gameobject.h"
#include "tile.h"

#include <QList>
#include <QTimer>

#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

class GameSystem
{

    public:enum Level
    {
        First,
        Second
    };

private:
    Vector2i tileSize;
    int scale;
    Board* board;

    int frames;
    int timeScale;
    QTimer* timer;

    Level level = GameSystem::First;
    QList<GameObject*> objects;

public:
    GameSystem(QWidget *parent, Vector2i tileSizeXY, int scale);

    int getScale();
    void setScale(int scaleValue);
    Vector2i getTileSize();
    void setTileSize(Vector2i tileSizeXY);
    Board* getBoard();
    void setBoard(Board* boardPointer);

    Level getLevel();
    void setLevel(Level levelName);

    void addObject(GameObject* object);
    void removeObject(GameObject* object);

};

#endif // GAMESYSTEM_H
*/
