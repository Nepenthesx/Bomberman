#include "gamemanager.h"

#include "graphicsmanager.h"
#include "gameobject.h"
#include "character.h"
#include "tile.h"
#include "graphicobject.h"

#include <QWidget>
#include <QList>
#include <QDebug>
#include <QTimer>
#include <QVector>

int GameManager::globalScale;


GameManager::GameManager(int globalScale, float frameInterval, Level level)
{
    GameManager::setGlobalScale(globalScale);
    this->frameInterval = frameInterval;
    this->level = level;

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGame()));
    timer->setInterval(frameInterval);
    timer->start();
}

void GameManager::updateGame()
{
    /*
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

    frameCount++;*/

    //qDebug() << frameCount;


    for (GraphicObject* object : graphicObjects)
    {
        object->update();
    }


    //UPDATE GRAPHICS MANAGER
    //graphicsManager->setObjectsList(gameObjects);
    //graphicsManager->update();
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
                GameObject* newTile = new WallTile(QVector<int>({x * GameManager::getGlobalScale(), y * GameManager::getGlobalScale()}), QVector<int>({GameManager::getGlobalScale(), GameManager::getGlobalScale()}));
                gameObjects.push_back(newTile);

                GraphicObject* newGTile = new GraphicObject(newTile, "/img/tile3.png", parent);
                graphicObjects.push_back(newGTile);
                newGTile->show();
            }
            else if (x < 5 && y < 5)
            {
                GameObject* newTile = new FloorTile(QVector<int>({x * GameManager::getGlobalScale(), y * GameManager::getGlobalScale()}), QVector<int>({GameManager::getGlobalScale(), GameManager::getGlobalScale()}));
                gameObjects.push_back(newTile);

                GraphicObject* newGTile = new GraphicObject(newTile, "/img/tile1.png", parent);
                graphicObjects.push_back(newGTile);
                newGTile->show();
            }
            else
            {
                GameObject* newTile = new RockTile(QVector<int>({x * GameManager::getGlobalScale(), y * GameManager::getGlobalScale()}), QVector<int>({GameManager::getGlobalScale(), GameManager::getGlobalScale()}));
                gameObjects.push_back(newTile);

                GraphicObject* newGTile = new GraphicObject(newTile, "/img/tile2.png", parent);
                graphicObjects.push_back(newGTile);
                newGTile->show();
            }
        }
    }

    GameObject* newPlayer = new Player(QVector<int>({3 * GameManager::getGlobalScale(), 3 * GameManager::getGlobalScale()}), QVector<int>({GameManager::getGlobalScale(), GameManager::getGlobalScale()}));
    gameObjects.push_back(newPlayer);

    GraphicObject* newGPlayer = new GraphicObject(newPlayer, "/img/character.png", parent);
    graphicObjects.push_back(newGPlayer);
    newGPlayer->show();

    //graphicsManager = new GraphicsManager(QVector<int>({tileWidth * GameObject::getGlobalScale(), tileHeight * GameObject::getGlobalScale()}), parent);
    //graphicsManager->setObjectsList(gameObjects);
    //graphicsManager->show();

}

void GameManager::createSecondLevel(QWidget* parent)
{

}

void GameManager::createThirdLevel(QWidget* parent)
{

}

int GameManager::getGlobalScale()
{
    return globalScale;
}

void GameManager::setGlobalScale(int scale)
{
    if (scale > 0)
        globalScale = scale;
    else
        globalScale = 32;
}

void GameManager::checkContact(GameObject* object)
{/*
    int myX = position[0];
    int myY = position[1];

    int objectX = object->getPosition()[0];
    int objectY = object->getPosition()[1];

    int myLeftEdge = myX;
    int myRightEdge = myX + globalScale * relativeScale;
    int myUpEdge = myY;
    int myDownEdge = myY + globalScale * relativeScale;

    int objectLeftEdge = objectX;
    int objectRightEdge = objectX + globalScale * object->getRelativeScale();
    int objectUpEdge = objectY;
    int objectDownEdge = objectY + globalScale * object->getRelativeScale();

    bool horizontalContact = false;
    bool verticalContact = false;

    if (myX <= objectX && myRightEdge > objectLeftEdge) //kontakt z prawej
        horizontalContact = true;
    else if (myX >= objectX && myLeftEdge < objectRightEdge) //kontakt z lewej
        horizontalContact = true;

    if (myY <= objectY && myDownEdge > objectUpEdge) //kontakt z dołu
        verticalContact = true;
    else if (myY >= objectY && myUpEdge < objectDownEdge) //kontakt z góry
        verticalContact = true;

    if (horizontalContact && verticalContact)
        objectsInContact.push_back(object);*/
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

