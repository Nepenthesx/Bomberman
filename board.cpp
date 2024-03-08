/*
#include "board.h"
#include "tile.h"

#include <QPainter>
#include <QRect>
#include <QPaintEvent>
#include <QList>
#include <QDebug>

#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

Board::Board(QWidget *parent, int widthTileVolume, int heightTileVolume, int scaleValue) : QWidget(parent)
{
    setTileWidth(widthTileVolume);
    setTileHeight(heightTileVolume);
    setScale(scaleValue);
    setFixedSize(tileWidth*getScale(), tileHeight*getScale());
    //setFirstLevel();

    setAttribute(Qt::WA_StaticContents);

    //polozenie, rozmiar
    setGeometry(0, 0, width(), height());
    image = new QImage(width(), height(), QImage::Format_ARGB32);

    //updateImages();
}

void Board::updateImages()
{
    QPainter painter(image);

    for (int y = 0; y < tileHeight; y++)
    {
        for (int x = 0; x < tileWidth; x++)
        {
            Vector2i tilePos = tiles(y, x)->getPosition();
            QRect r(tilePos(0), tilePos(1), scale, scale);
            //painter.fillRect(*r, Qt::yellow);
            painter.drawPixmap(r, tiles(y, x)->getPicture());
        }
    }
}

void Board::setFirstLevel()
{
    tiles.resize(tileHeight, tileWidth);

    int number = 0;

    for (int y = 0; y < tileHeight; y++)
    {
        for (int x = 0; x < tileWidth; x++)
        {
            if (x == 0 || x == 1 || x == tileWidth - 1 || x == tileWidth - 2 || y == 0 || y == 1 || y == tileHeight - 1 || y == tileHeight - 2)
            {
                tiles(y, x) = new Tile("/img/tile3.png", 0, 0);
            }
            else if (x < 5 && y < 5)
            {
                tiles(y, x) = new Tile("/img/tile1.png", 0, 1);
            }
            else
            {
                tiles(y, x) = new Tile("/img/tile2.png", 1, 0);
            }

            tiles(y, x)->setPosition(x * scale, y * scale);
            tiles(y, x)->number = number;
            number++;
        }
    }

    /// Zapelnienie calosci

    for (int y = 0; y < tileHeight; y++)
    {
        for (int x = 0; x < tileWidth; x++)
        {
            tiles(y, x) = new Tile();
            tiles(y, x)->setPosition(x * scale, y * scale);
            tiles(y, x)->setPicture("/img/img1.png");
        }
    }

    for (int y = 0; y < tileHeight; y++)
    {
        for (int x = 0; x < tileWidth; x++)
        {
            if (x != 0)
                tiles(y, x)->setLeftTile(tiles(y, x - 1));
            else
                tiles(y, x)->setLeftTile(nullptr);
            if (x != tileWidth - 1)
                tiles(y, x)->setRightTile(tiles(y, x + 1));
            else
                tiles(y, x)->setRightTile(nullptr);
            if (y != 0)
                tiles(y, x)->setUpTile(tiles(y - 1, x));
            else
                tiles(y, x)->setUpTile(nullptr);
            if (y != tileHeight - 1)
                tiles(y, x)->setDownTile(tiles(y + 1, x));
            else
                tiles(y, x)->setDownTile(nullptr);
        }
    }

}

int Board::getTileWidth()
{
    return tileWidth;
}

void Board::setTileWidth(int tileVolume)
{
    tileWidth = tileVolume;
}

int Board::getTileHeight()
{
    return tileHeight;
}

void Board::setTileHeight(int tileVolume)
{
    tileHeight = tileVolume;
}

int Board::getScale()
{
    return scale;
}

void Board::setScale(int scaleValue)
{
    scale = scaleValue;
}

Tile* Board::getTile(int y, int x)
{
    return tiles(y, x);
}

void Board::changeTile(Tile* tile, int row, int column)
{
    tiles(row, column) = tile;
}

void Board::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, *image, dirtyRect);
}
*/
