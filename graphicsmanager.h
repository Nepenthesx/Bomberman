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

//    QImage *image;
    Matrix<Tile*, Dynamic, Dynamic> tiles;
    QList<GameObject*> objects;

    int frameNumber = 0;
    int frameInterval;
    QTimer* timer;

    Level level = GraphicsManager::First;

public:
    GraphicsManager(QWidget* parent = nullptr, Vector2i tileSizeXY = Vector2i(20, 20), int scaleValue = 32, int frameIntervalMS = 1000);

    int getFrameNumber();
    void setFrameNumber(int number);
    int getFrameInterval();
    void setFrameInterval(int frameIntervalMS);

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

    void updateGraphic();

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
