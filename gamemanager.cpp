#include "gamemanager.h"

#include "graphicsmanager.h"
#include "gameobject.h"
#include "character.h"
#include "tile.h"

#include <QWidget>
#include <QList>
#include <QDebug>
#include <QTimer>
#include <QVector>


GameManager::GameManager(int globalScale, float frameInterval, Level level)
{
    GameObject::setGlobalScale(globalScale);
    this->frameInterval = frameInterval;
    this->level = level;

    //TIMER!!!! z updateGame
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGame()));
    timer->setInterval(frameInterval);
    timer->start();
}

void GameManager::updateGame()
{
    //MOVE
    for (GameObject* object : gameObjects)
    {
        object->move();
    }

    //CHECK CONTACT
    for (GameObject* object : gameObjects)
    {
        //wyczyść kolizje z poprzedniego update
        object->clearObjectsInContact();

        for (GameObject* innerObject : gameObjects)
        {
            //jeśli nie jestem to ja
            //oraz mogę sprawdzać tylko obiekty wchodzące w interakcje (np. podłoga jest bez sensu do sprawdzania)
            if (object != innerObject && innerObject->getInteractivity())
                object->checkContact(innerObject);
        }
    }

    //INTERACT
    for (GameObject* object : gameObjects)
    {
        object->interact();
    }

    //IF ZERO DURABILITY
    for (GameObject* object : gameObjects)
    {
        if (object->getDurability() <= 0)
            object->onDurabilityLoss();
    }

    frameCount++;

    //qDebug() << frameCount;

    //UPDATE GRAPHICS MANAGER
    graphicsManager->setObjectsList(gameObjects);
    graphicsManager->update();
}

void GameManager::createFirstLevel(QWidget* parent)
{
    int tileHeight = 10;
    int tileWidth = 20;

    for (int y = 0; y < tileHeight; y++)
    {
        for (int x = 0; x < tileWidth; x++)
        {
            if (x == 0 || x == 1 || x == tileWidth - 1 || x == tileWidth - 2 || y == 0 || y == 1 || y == tileHeight - 1 || y == tileHeight - 2)
            {
                GameObject* newTile = new WallTile(QVector<int>({x * GameObject::getGlobalScale(), y * GameObject::getGlobalScale()}));
                gameObjects.push_back(newTile);
            }
            else if (x < 5 && y < 5)
            {
                GameObject* newTile = new FloorTile(QVector<int>({x * GameObject::getGlobalScale(), y * GameObject::getGlobalScale()}));
                gameObjects.push_back(newTile);
            }
            else
            {
                GameObject* newTile = new RockTile(QVector<int>({x * GameObject::getGlobalScale(), y * GameObject::getGlobalScale()}));
                gameObjects.push_back(newTile);
            }
        }
    }

    GameObject* newPlayer = new Player(QVector<int>({3 * GameObject::getGlobalScale(), 3 * GameObject::getGlobalScale()}));
    gameObjects.push_back(newPlayer);

    graphicsManager = new GraphicsManager(QVector<int>({tileWidth * GameObject::getGlobalScale(), tileHeight * GameObject::getGlobalScale()}), parent);
    graphicsManager->setObjectsList(gameObjects);
    graphicsManager->show();

}

void GameManager::createSecondLevel(QWidget* parent)
{

}

void GameManager::createThirdLevel(QWidget* parent)
{

}

int GameManager::getFrameCount()
{
    return frameCount;
}

float GameManager::getFrameInterval()
{
    return frameInterval;
}

void GameManager::setFrameInterval(float frameInterval)
{
    if (frameInterval > 0)
        this->frameInterval = frameInterval;
}

GameManager::Level GameManager::getLevel()
{
    return level;
}

void GameManager::setLevel(GameManager::Level level)
{
    this->level = level;
}

void GameManager::addObject(GameObject* object)
{
    gameObjects.push_back(object);
}

void GameManager::removeObject(GameObject* object)
{
    gameObjects.removeOne(object);
}

void GameManager::startLevel(QWidget* parent)
{
    frameCount = 0;

    switch (level)
    {
    case GameManager::First:
        createFirstLevel(parent);
        break;

    case GameManager::Second:
        createSecondLevel(parent);
        break;

    case GameManager::Third:
        createThirdLevel(parent);
        break;

    }
}

void GameManager::endLevel()
{
    for (GameObject* object : gameObjects)
    {
        delete object;
    }

    gameObjects.clear();
}

