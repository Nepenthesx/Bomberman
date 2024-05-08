#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "gameobject.h"
#include "graphicobject.h"
#include "player.h"
#include "floortile.h"
#include "rocktile.h"
#include "walltile.h"
#include "bomb.h"
#include "crossbomb.h"
#include "squarebomb.h"
#include "bombtypeupgrade.h"
#include "bombpowerupgrade.h"
#include "bombcountupgrade.h"
#include "bomber.h"

#include <QObject>
#include <QWidget>
#include <QList>
#include <QSet>
#include <QTimer>
#include <QDebug>
#include <QVector>


//MOŻE BYĆ TYLKO JEDEN - WYKORZYSTAĆ METODĘ STATYCZNĄ
class GameManager : public QObject
{
    Q_OBJECT

private:
    static QList<GameObject*> gameObjects; //POWINNO BYĆ STATYCZNE, ABY USUWANE OBIEKTY USUWAŁY SIĘ Z LISTY!!!
    static QList<GraphicObject*> graphicObjects;
    static QWidget* window;

    static int globalScale;
    int frameCount = 0;
    float frameInterval;
    QTimer* timer;

    void removeObject(GameObject* object);

public:
    GameManager(int globalScale, QWidget* window, float frameInterval = 1000);

    static int getGlobalScale();
    static void setGlobalScale(int scale);

    int getFrameCount();
    float getFrameInterval();
    void setFrameInterval(float frameInterval);

    void startLevel();
    static void endLevel();

    static void createFloorTile(QVector<int> position);
    static void createRockTile(QVector<int> position);
    static void createWallTile(QVector<int> position);
    static void createPlayer(QVector<int> position, int speed);
    static void createEnemy(QVector<int> position, int speed);
    static void createBomb(QVector<int> position, Bomber* owner, int explosionPower, Bomber::BombType bombType);
    static void createBombTypeUpgrade(QVector<int> position);
    static void createBombPowerUpgrade(QVector<int> position);
    static void createBombCountUpgrade(QVector<int> position);

    static QList<GameObject*> getObjectsInRange(GameObject* object, int range);
    static QList<GameObject*> getObjectsInContact(QVector<int> objectPosition, QVector<int> objectSize);
    static QSet<GameObject*> getObjectsInContactArea(QVector<int> basePosition, QSet<QVector<int>> relativePositions, QVector<int> objectSize);
    static bool checkContact(QVector<int> firstObjectPosition, QVector<int> firstObjectSize, QVector<int> secondObjectPosition, QVector<int> secondObjectSize);

public slots:
    void updateGame();
};

#endif // GAMEMANAGER_H
