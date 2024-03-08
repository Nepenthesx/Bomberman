/*
#include "gamesystem.h"
#include "board.h"
#include "player.h"
#include "gameobject.h"

#include <QList>
#include <QTimer>

#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

GameSystem::GameSystem(QWidget* parent = nullptr, Vector2i tileSize = Vector2i(20, 20), int scale = 10)
{
    setScale(scale);
    setTileSize(tileSize);

    Board* newBoard = new Board(parent, getTileSize()(0), getTileSize()(1), scale);
    setBoard(newBoard);
    if (getLevel() == GameSystem::First)
        getBoard()->setFirstLevel();
    getBoard()->updateImages();
    getBoard()->show();

    Player* newPlayer = new Player(Vector2i(3*getScale(), 3*getScale()), 0.5f*getScale(), "img/character.png");
    newPlayer->setGameSystem(this);
    addObject(newPlayer);

    timer = new QTimer();
}

int GameSystem::getScale()
{
    return scale;
}

void GameSystem::setScale(int scaleValue)
{
    scale = scaleValue;
}

Vector2i GameSystem::getTileSize()
{
    return tileSize;
}

void GameSystem::setTileSize(Vector2i tileSizeXY)
{
    tileSize = tileSizeXY;
}

Board* GameSystem::getBoard()
{
    return board;
}

void GameSystem::setBoard(Board* boardPointer)
{
    board = boardPointer;
}

GameSystem::Level GameSystem::getLevel()
{
    return level;
}

void GameSystem::setLevel(GameSystem::Level levelName)
{
    level = levelName;
}

void GameSystem::addObject(GameObject* object)
{
    objects.push_back(object);
}

void GameSystem::removeObject(GameObject *object)
{
    objects.removeOne(object);
}
*/
