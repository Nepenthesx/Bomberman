#ifndef BOARD_H
#define BOARD_H

#include "gameobject.h"
#include "tile.h"

#include <QWidget>
#include <QList>

#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

class Board : public QWidget
{
    Q_OBJECT

    public:enum Level
    {
        First,
        Second
    };

private:
    int tileWidth;
    int tileHeight;
    int scale;

    Level level = Board::First;
    QImage *image;
    Matrix<Tile*, Dynamic, Dynamic> tiles;
    QList<GameObject*> objects;

public:
    //explicit Board(QWidget *parent = nullptr);
    Board(QWidget *parent = nullptr, int widthTileVolume = 10, int heightTileVolume = 10, int scale = 10);

    int getTileWidth();
    void setTileWidth(int tileVolue);
    int getTileHeight();
    void setTileHeight(int tileVolume);
    int getScale();
    void setScale(int scaleValue);

    void setLevelSurface();

    void changeTile(Tile* tile, int row, int column);
    void addObject(GameObject* object);
    void removeObject(GameObject* object);

    void updateImages();

protected:
    void paintEvent(QPaintEvent *event) override;

//signals:
};

#endif // BOARD_H
