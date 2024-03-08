#include "graphicsmanager.h"
#include "gameobject.h"
#include "tile.h"
#include "player.h"

#include <QList>
#include <QTimer>
#include <QPainter>
#include <QRect>
#include <QPaintEvent>
#include <QDebug>

#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;


GraphicsManager::GraphicsManager(QWidget* parent, Vector2i tileSizeXY, int scaleValue, int frameIntervalMS) : QWidget(parent)
{
    setFocus();

    setScale(scaleValue);
    setTileSize(tileSizeXY);
    setFrameInterval(frameIntervalMS);

    if (getLevel() == GraphicsManager::First)
        setFirstLevel();

    setFixedSize(getTileSize()(0)*getScale(), getTileSize()(1)*getScale());
    setGeometry(0, 0, width(), height());

    Player* newPlayer = new Player(Vector2i(3*getScale(), 3*getScale()), GameObject::Center, 0.2f*getScale(), "/img/character.png", 0.5f);
    connect(this, SIGNAL(leftArrowPressed()), newPlayer, SLOT(moveLeft()));
    connect(this, SIGNAL(rightArrowPressed()), newPlayer, SLOT(moveRight()));
    connect(this, SIGNAL(upArrowPressed()), newPlayer, SLOT(moveUp()));
    connect(this, SIGNAL(downArrowPressed()), newPlayer, SLOT(moveDown()));
    addObject(newPlayer);


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->setInterval(getFrameInterval());
    timer->start();
}

int GraphicsManager::getFrameNumber()
{
    return frameNumber;
}

void GraphicsManager::setFrameNumber(int number)
{
    frameNumber = number;
}

int GraphicsManager::getFrameInterval()
{
    return frameInterval;
}

void GraphicsManager::setFrameInterval(int frameIntervalMS)
{
    frameInterval = frameIntervalMS;
}

int GraphicsManager::getScale()
{
    return scale;
}

void GraphicsManager::setScale(int scaleValue)
{
    scale = scaleValue;
}

Vector2i GraphicsManager::getTileSize()
{
    return tileSize;
}

void GraphicsManager::setTileSize(Vector2i tileSizeXY)
{
    tileSize = tileSizeXY;
}

GraphicsManager::Level GraphicsManager::getLevel()
{
    return level;
}

void GraphicsManager::setLevel(GraphicsManager::Level levelName)
{
    level = levelName;
}

Tile* GraphicsManager::getTile(int y, int x)
{
    return tiles(y, x);
}

void GraphicsManager::changeTile(Tile* tile, int row, int column)
{
    tiles(row, column) = tile;
}

void GraphicsManager::addObject(GameObject* object)
{
    objects.push_back(object);
}

void GraphicsManager::removeObject(GameObject *object)
{
    objects.removeOne(object);
}

void GraphicsManager::setFirstLevel()
{
    int tileWidth = getTileSize()(0);
    int tileHeight = getTileSize()(1);

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
}

void GraphicsManager::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    int tileWidth = getTileSize()(0);
    int tileHeight = getTileSize()(1);

    for (int y = 0; y < tileHeight; y++)
    {
        for (int x = 0; x < tileWidth; x++)
        {
            Vector2i tilePos = tiles(y, x)->getPosition();
            QRect rect(tilePos(0), tilePos(1), tiles(y, x)->getRelativeScale() * getScale(), tiles(y, x)->getRelativeScale() * getScale());
            painter.drawPixmap(rect, tiles(y, x)->getPicture());
        }
    }

    for(GameObject* object : objects)
    {
        Vector2i objectPos = object->getPosition();
        if (object->getPivotLocation() == GameObject::Center)
            objectPos = Vector2i(objectPos(0) + getScale()/2 * object->getRelativeScale(), objectPos(1) + getScale()/2 * object->getRelativeScale());
        QRect rect(objectPos(0), objectPos(1), object->getRelativeScale() * getScale(), object->getRelativeScale() * getScale());
        painter.drawPixmap(rect, object->getPicture());
    }

    QRect rect(64, 64, getScale(), getScale());
    painter.drawText(rect, QString::number(getFrameNumber()));
    setFrameNumber(getFrameNumber() + 1);
}

void GraphicsManager::keyPressEvent(QKeyEvent* event)
{

    switch (event->key())
    {
    case Qt::Key_Left:
        emit leftArrowPressed();
        break;
    case Qt::Key_Right:
        emit rightArrowPressed();
        break;
    case Qt::Key_Up:
        emit upArrowPressed();
        break;
    case Qt::Key_Down:
        emit downArrowPressed();
        break;
    case Qt::Key_Space:
        emit spacePressed();
        break;
    }
}
