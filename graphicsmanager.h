#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H

#include "gameobject.h"

#include <QWidget>
#include <QList>
#include <QVector>


class GraphicsManager : public QWidget
{
    Q_OBJECT

private:
    QList<GameObject*> objects;

public:
    GraphicsManager(QVector<int> size, QWidget* parent = nullptr);
    void setObjectsList(QList<GameObject*> objects);

protected:
    void paintEvent(QPaintEvent* event) override;

};

#endif // GRAPHICSMANAGER_H




/*
#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H

#include "gameobject.h"
#include "tile.h"

#include <QWidget>
#include <QList>

#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

class GraphicsManager : public QWidget
{
    Q_OBJECT

    public:enum Level
    {
        First,
        Second
    };

private:
    Vector2i tileSize;
    int scale;

    Matrix<Tile*, Dynamic, Dynamic> tiles;
    QList<GameObject*> objects;

    int frameNumber = 0;
    float frameInterval;
    QTimer* timer;

    Level level = GraphicsManager::First;

public:
    GraphicsManager(QWidget* parent = nullptr, Vector2i tileSizeXY = Vector2i(20, 20), int scaleValue = 32, float frameIntervalMS = 1000);

    int getFrameNumber();
    void setFrameNumber(int number);
    float getFrameInterval();
    void setFrameInterval(float frameIntervalMS);

    int getScale();
    void setScale(int scaleValue);
    Vector2i getTileSize();
    void setTileSize(Vector2i tileSizeXY);
    Level getLevel();
    void setLevel(Level levelName);

    Tile* getTile(int x, int y);
    void changeTile(Tile* tile, int row, int column);
    void addObject(GameObject* object);
    void removeObject(GameObject* object);

    void setFirstLevel();

protected:
    void paintEvent(QPaintEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;

signals:
    void leftArrowPressed();
    void rightArrowPressed();
    void upArrowPressed();
    void downArrowPressed();
    void spacePressed();
};

#endif // GRAPHICSMANAGER_H
*/
