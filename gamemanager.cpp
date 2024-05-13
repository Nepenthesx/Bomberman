#include "gamemanager.h"

#include "player.h"
#include "enemy.h"
#include "floortile.h"
#include "rocktile.h"
#include "walltile.h"
#include "crossbomb.h"
#include "squarebomb.h"
#include "bombtypeupgrade.h"
#include "bombpowerupgrade.h"
#include "bombcountupgrade.h"

int GameManager::globalScale;
QList<GameObject*> GameManager::gameObjects;
QList<GraphicObject*> GameManager::graphicObjects;
QWidget* GameManager::window;


GameManager::GameManager(int globalScale, QWidget* window, float frameInterval)
{
    setGlobalScale(globalScale);
    setFrameInterval(frameInterval);
    this->window = window;

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGame()));
    timer->setInterval(frameInterval);
    timer->start();
}

GameManager& GameManager::getInstance()
{
    static GameManager instance;
    return instance;
}

void GameManager::updateGame()
{
    QVector<GameObject*> objectsToDestroy;

    for (GameObject* object : gameObjects)
    {
        if (object->checkActivity())
            object->update();
        else
            objectsToDestroy.push_back(object);
    }

    for (GameObject* object : objectsToDestroy)
    {
        removeObject(object);
    }

    GraphicObject::sortByPriority(graphicObjects);
    for (GraphicObject* object : graphicObjects)
    {
        object->update();
    }

    frameCount++;
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
    else
        this->frameInterval = 500;
}

void GameManager::removeObject(GameObject* object)
{
    gameObjects.removeOne(object);

    for (GraphicObject* graphicObject : graphicObjects)
    {
        if (graphicObject->getGameObject() == object)
        {
            graphicObjects.removeOne(graphicObject);
            delete graphicObject;
            break;
        }
    }

    delete object;
}

void GameManager::startLevel()
{
    frameCount = 0;

    int tileHeight = 10;
    int tileWidth = 20;

    for (int y = 0; y < tileHeight; y++)
    {
        for (int x = 0; x < tileWidth; x++)
        {
            if (x == 0 || x == 1 || x == tileWidth - 1 || x == tileWidth - 2 || y == 0 || y == 1 || y == tileHeight - 1 || y == tileHeight - 2)
                createWallTile(QVector<int>({x * globalScale, y * globalScale}));
            else if ((x < 5 && y < 5) || (x == tileWidth - 3 || x == tileWidth - 4))
                createFloorTile(QVector<int>({x * globalScale, y * globalScale}));
            else
                createRockTile(QVector<int>({x * globalScale, y * globalScale}));
        }
    }

    createPlayer(QVector<int>({3 * globalScale, 3 * globalScale}), globalScale);
    createEnemy(QVector<int>({(tileWidth - 3) * globalScale, 3 * globalScale}), globalScale);
}

void GameManager::endLevel()
{
    for (GameObject* object : gameObjects)
    {
        object->desactive();
    }
}

void GameManager::createFloorTile(QVector<int> position)
{
    QVector<int> size(globalScale, globalScale);

    GameObject* newTile = new FloorTile(position, size);
    gameObjects.push_back(newTile);

    GraphicObject* newGTile = new GraphicObject(newTile, "/img/tile1.png", window, 0);
    graphicObjects.push_back(newGTile);
    newGTile->show();
}

void GameManager::createRockTile(QVector<int> position)
{
    QVector<int> size(globalScale, globalScale);

    GameObject* newTile = new RockTile(position, size);
    gameObjects.push_back(newTile);

    GraphicObject* newGTile = new GraphicObject(newTile, "/img/tile2.png", window, 0);
    graphicObjects.push_back(newGTile);
    newGTile->show();
}

void GameManager::createWallTile(QVector<int> position)
{
    QVector<int> size(globalScale, globalScale);

    GameObject* newTile = new WallTile(position, size);
    gameObjects.push_back(newTile);

    GraphicObject* newGTile = new GraphicObject(newTile, "/img/tile3.png", window, 0);
    graphicObjects.push_back(newGTile);
    newGTile->show();
}

void GameManager::createPlayer(QVector<int> position, int speed)
{
    QVector<int> size(globalScale, globalScale);

    GameObject* newPlayer = new Player(position, size, speed);
    gameObjects.push_back(newPlayer);

    GraphicObject* newGPlayer = new GraphicObject(newPlayer, "/img/player.png", window, 3);
    graphicObjects.push_back(newGPlayer);
    newGPlayer->show();
}

void GameManager::createEnemy(QVector<int> position, int speed)
{
    QVector<int> size(globalScale, globalScale);

    GameObject* newEnemy = new Enemy(position, size, speed);
    gameObjects.push_back(newEnemy);

    GraphicObject* newGEnemy = new GraphicObject(newEnemy, "/img/enemy.png", window, 4);
    graphicObjects.push_back(newGEnemy);
    newGEnemy->show();
}

void GameManager::createBomb(QVector<int> position, Bomber* owner, int explosionPower, Bomber::BombType bombType)
{
    QVector<int> size(globalScale, globalScale);

    GameObject* newBomb;
    GraphicObject* newGBomb;

    switch (bombType)
    {
    case Bomber::Cross:
        newBomb = new CrossBomb(owner, position, size, explosionPower);
        newGBomb = new GraphicObject(newBomb, "/img/bomb1.png", window, 2);
        break;
    case Bomber::Square:
        newBomb = new SquareBomb(owner, position, size, explosionPower);
        newGBomb = new GraphicObject(newBomb, "/img/bomb2.png", window, 2);
        break;
    default:
        newBomb = new CrossBomb(owner, position, size, explosionPower);
        newGBomb = new GraphicObject(newBomb, "/img/bomb1.png", window, 2);
        break;
    }

    gameObjects.push_back(newBomb);
    graphicObjects.push_back(newGBomb);
    newGBomb->show();
}

void GameManager::createBombTypeUpgrade(QVector<int> position)
{
    QVector<int> size(globalScale, globalScale);

    GameObject* newUpgrade = new BombTypeUpgrade(position, size);
    gameObjects.push_back(newUpgrade);

    GraphicObject* newGUpgrade = new GraphicObject(newUpgrade, "/img/upgrade1.png", window, 1);
    graphicObjects.push_back(newGUpgrade);
    newGUpgrade->show();
}

void GameManager::createBombPowerUpgrade(QVector<int> position)
{
    QVector<int> size(globalScale, globalScale);

    GameObject* newUpgrade = new BombPowerUpgrade(position, size);
    gameObjects.push_back(newUpgrade);

    GraphicObject* newGUpgrade = new GraphicObject(newUpgrade, "/img/upgrade2.png", window, 1);
    graphicObjects.push_back(newGUpgrade);
    newGUpgrade->show();
}

void GameManager::createBombCountUpgrade(QVector<int> position)
{
    QVector<int> size(globalScale, globalScale);

    GameObject* newUpgrade = new BombCountUpgrade(position, size);
    gameObjects.push_back(newUpgrade);

    GraphicObject* newGUpgrade = new GraphicObject(newUpgrade, "/img/upgrade3.png", window, 1);
    graphicObjects.push_back(newGUpgrade);
    newGUpgrade->show();
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
    QVector<int> objectPositionU = QVector<int>({objectBasePosition[0], objectBasePosition[1] - range});
    objectsInRange.append(getObjectsInContact(objectPositionU, object->getSize()));
    //DÓŁ
    QVector<int> objectPositionD = QVector<int>({objectBasePosition[0], objectBasePosition[1] + range});
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

QSet<GameObject*> GameManager::getObjectsInContactArea(QVector<int> basePosition, QSet<QVector<int>> relativePositions, QVector<int> objectSize)
{
    QSet<GameObject*> objectsInContactArea;
    QSet<QVector<int>> globalObjectPositions;
    for(QVector<int> relativePosition : relativePositions)
    {
        QVector<int> globalPosition({basePosition[0] + globalScale * relativePosition[0], basePosition[1] + globalScale * relativePosition[1]});
        globalObjectPositions.insert(globalPosition);
    }

    for(QVector<int> objectPosition : globalObjectPositions)
    {
        QList<GameObject*> objectsInContactAreaL(getObjectsInContact(objectPosition, objectSize));

        for(GameObject* object : objectsInContactAreaL)
        {
            objectsInContactArea.insert(object);
        }
    }

    return objectsInContactArea;
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

