#include "gamemanager.h"


int GameManager::globalScale;
QList<GameObject*> GameManager::gameObjects;
QList<GraphicObject*> GameManager::graphicObjects;
QWidget* GameManager::widgetParent;


GameManager::GameManager(int globalScale, float frameInterval, Level level, QWidget* widgetParent)
{
    GameManager::setGlobalScale(globalScale);
    this->frameInterval = frameInterval;
    this->level = level;
    this->widgetParent = widgetParent;

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGame()));
    timer->setInterval(frameInterval);
    timer->start();
}

void GameManager::updateGame()
{
    for (GameObject* object : gameObjects)
    {
        object->update();
    }

    GraphicObject::sortByPriority(graphicObjects);
    for (GraphicObject* object : graphicObjects)
    {
        object->update();
    }

    frameCount++;
}

void GameManager::createFirstLevel()
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

                GraphicObject* newGTile = new GraphicObject(newTile, "/img/tile3.png", widgetParent, 0);
                graphicObjects.push_back(newGTile);
                newGTile->show();
            }
            else if (x < 5 && y < 5)
            {
                GameObject* newTile = new FloorTile(QVector<int>({x * GameManager::getGlobalScale(), y * GameManager::getGlobalScale()}), QVector<int>({GameManager::getGlobalScale(), GameManager::getGlobalScale()}));
                gameObjects.push_back(newTile);

                GraphicObject* newGTile = new GraphicObject(newTile, "/img/tile1.png", widgetParent, 0);
                graphicObjects.push_back(newGTile);
                newGTile->show();
            }
            else
            {
                GameObject* newTile = new RockTile(QVector<int>({x * GameManager::getGlobalScale(), y * GameManager::getGlobalScale()}), QVector<int>({GameManager::getGlobalScale(), GameManager::getGlobalScale()}));
                gameObjects.push_back(newTile);

                GraphicObject* newGTile = new GraphicObject(newTile, "/img/tile2.png", widgetParent, 0);
                graphicObjects.push_back(newGTile);
                newGTile->show();
            }
        }
    }

    GameObject* newPlayer = new Player(QVector<int>({3 * GameManager::getGlobalScale(), 3 * GameManager::getGlobalScale()}), QVector<int>({GameManager::getGlobalScale(), GameManager::getGlobalScale()}));
    gameObjects.push_back(newPlayer);

    GraphicObject* newGPlayer = new GraphicObject(newPlayer, "/img/character.png", widgetParent, 2);
    graphicObjects.push_back(newGPlayer);
    newGPlayer->show();
}

void GameManager::createSecondLevel()
{

}

void GameManager::createThirdLevel()
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
    else
        this->frameInterval = 500;
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

    switch (level)
    {
    case GameManager::First:
        createFirstLevel();
        break;

    case GameManager::Second:
        createSecondLevel();
        break;

    case GameManager::Third:
        createThirdLevel();
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

void GameManager::createBomb(Bomber* owner, QVector<int> position, int explosionPower, Bomber::BombType bombType)
{
    GameObject* newBomb;
    //GameObject* newPlayer = new Player();
    switch (bombType)
    {
    case Bomber::Cross:
        newBomb = new CrossBomb(owner, position, QVector<int>({GameManager::getGlobalScale(), GameManager::getGlobalScale()}), explosionPower);
        break;
    case Bomber::Square:
        break;
    default:
        newBomb = new CrossBomb(owner, position, QVector<int>({GameManager::getGlobalScale(), GameManager::getGlobalScale()}), explosionPower);
        break;
    }

    gameObjects.push_back(newBomb);

    GraphicObject* newGBomb = new GraphicObject(newBomb, "/img/item3.png", widgetParent, 1);
    graphicObjects.push_back(newGBomb);
    newGBomb->show();
}

void GameManager::createFloor(QVector<int> position)
{
    GameObject* newTile = new FloorTile(position,QVector<int>({GameManager::getGlobalScale(), GameManager::getGlobalScale()}));
    gameObjects.push_back(newTile);

    GraphicObject* newGTile = new GraphicObject(newTile, "/img/tile1.png", widgetParent, 0);
    graphicObjects.push_back(newGTile);
    newGTile->show();
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
        QVector<int> globalPosition({basePosition[0] + GameManager::getGlobalScale() * relativePosition[0], basePosition[1] + GameManager::getGlobalScale() * relativePosition[1]});
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

