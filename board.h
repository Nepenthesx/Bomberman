/*
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

private:
    int tileWidth;
    int tileHeight;
    int scale;

    QImage *image;
    Matrix<Tile*, Dynamic, Dynamic> tiles;

public:
    Board(QWidget *parent, int widthTileVolume, int heightTileVolume, int scale);

    int getTileWidth();
    void setTileWidth(int tileVolue);
    int getTileHeight();
    void setTileHeight(int tileVolume);
    int getScale();
    void setScale(int scaleValue);

    void setFirstLevel();

    Tile* getTile(int x, int y);
    void changeTile(Tile* tile, int row, int column);

    void updateImages();

protected:
    void paintEvent(QPaintEvent *event) override;

};

#endif // BOARD_H
*/
