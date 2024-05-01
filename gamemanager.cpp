#include "gamemanager.h"

#include "graphicsmanager.h"
#include "gameobject.h"
#include "character.h"
#include "tile.h"
#include "graphicobject.h"

#include <QWidget>
#include <QList>
#include <QSet>
#include <QDebug>
#include <QTimer>
#include <QVector>

int GameManager::globalScale;
QList<GameObject*> GameManager::gameObjects;


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

    //MOVE
    for (GameObject* object : gameObjects)
    {
        object->update();
    }
    /*
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

QList<GameObject*> GameManager::getObjectsInRange(GameObject* object, int range)
{
    QList<GameObject*> objectsInRange;

    QVector<int> objectBasePosition = object->getPosition();

    //PRAWO
    QVector<int> objectPositionR = QVector<int>({objectBasePosition[0] + range, objectBasePosition[1]});
    objectsInRange.append(getObjectsInContact(objectPositionR, object->getSize()));
    //LEWO
    QVector<int> objectPositionL = QVector<int>({objectBasePosition[0] - range, objectBasePosition[1]});
    objectsInRange.append(getObjectsInContact(objectPositionL, object->getSize()));
    //GÓRA
    QVector<int> objectPositionU = QVector<int>({objectBasePosition[0], objectBasePosition[1] + range});
    objectsInRange.append(getObjectsInContact(objectPositionU, object->getSize()));
    //DÓŁ
    QVector<int> objectPositionD = QVector<int>({objectBasePosition[0], objectBasePosition[1] - range});
    objectsInRange.append(getObjectsInContact(objectPositionD, object->getSize()));


    //USUŃ DUPLIKATY
    QSet<GameObject*> set(objectsInRange.begin(), objectsInRange.end());

    return set.values();
}

QList<GameObject*> GameManager::getObjectsInContact(QVector<int> objectPosition, QVector<int> objectSize)
{
    QList<GameObject*> objectsInContact;

    for (GameObject* listObject : gameObjects)
    {
        if (checkContact(objectPosition, objectSize, listObject->getPosition(), listObject->getSize()))
        {
            objectsInContact.push_back(listObject);
        }
    }

    return objectsInContact;
}

bool GameManager::checkContact(QVector<int> firstObjectPosition, QVector<int> firstObjectSize, QVector<int> secondObjectPosition, QVector<int> secondObjectSize)
{
    int firstX = firstObjectPosition[0];
    int firstY = firstObjectPosition[1];
    int firstWidth = firstObjectSize[0];
    int firstHeight = firstObjectSize[1];

    int secondX = secondObjectPosition[0];
    int secondY = secondObjectPosition[1];
    int secondWidth = secondObjectSize[0];
    int secondHeight = secondObjectSize[1];

    int firstLeftEdge = firstX;
    int firstRightEdge = firstX + firstWidth;
    int firstUpEdge = firstY;
    int firstDownEdge = firstY + firstHeight;

    int secondLeftEdge = secondX;
    int secondRightEdge = secondX + secondWidth;
    int secondUpEdge = secondY;
    int secondDownEdge = secondY + secondHeight;

    bool horizontalContact = false;
    bool verticalContact = false;

    if (firstX <= secondX && firstRightEdge > secondLeftEdge) //kontakt z prawej
        horizontalContact = true;
    else if (firstX >= secondX && firstLeftEdge < secondRightEdge) //kontakt z lewej
        horizontalContact = true;

    if (firstY <= secondY && firstDownEdge > secondUpEdge) //kontakt z dołu
        verticalContact = true;
    else if (firstY >= secondY && firstUpEdge < secondDownEdge) //kontakt z góry
        verticalContact = true;

    if (horizontalContact && verticalContact)
        return true;
    else
        return false;
}

/*
QList<GameObject*> GameManager::getObjectsInContact(GameObject* object)
{
    QList<GameObject*> objectsInContact;

    for (GameObject* listObject : gameObjects)
    {
        if (listObject != object && checkContact(object, listObject))
        {
            objectsInContact.push_back(listObject);
        }
    }

    return objectsInContact;
}

bool GameManager::checkContact(GameObject* firstObject, GameObject* secondObject)
{
    int firstX = firstObject->getPosition()[0];
    int firstY = firstObject->getPosition()[1];
    int firstWidth = firstObject->getSize()[0];
    int firstHeight = firstObject->getSize()[1];

    int secondX = secondObject->getPosition()[0];
    int secondY = secondObject->getPosition()[1];
    int secondWidth = secondObject->getSize()[0];
    int secondHeight = secondObject->getSize()[1];

    int firstLeftEdge = firstX;
    int firstRightEdge = firstX + firstWidth;
    int firstUpEdge = firstY;
    int firstDownEdge = firstY + firstHeight;

    int secondLeftEdge = secondX;
    int secondRightEdge = secondX + secondWidth;
    int secondUpEdge = secondY;
    int secondDownEdge = secondY + secondHeight;

    bool horizontalContact = false;
    bool verticalContact = false;

    if (firstX <= secondX && firstRightEdge > secondLeftEdge) //kontakt z prawej
        horizontalContact = true;
    else if (firstX >= secondX && firstLeftEdge < secondRightEdge) //kontakt z lewej
        horizontalContact = true;

    if (firstY <= secondY && firstDownEdge > secondUpEdge) //kontakt z dołu
        verticalContact = true;
    else if (firstY >= secondY && firstUpEdge < secondDownEdge) //kontakt z góry
        verticalContact = true;

    if (horizontalContact && verticalContact)
        return true;
    else
        return false;
}*/

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

