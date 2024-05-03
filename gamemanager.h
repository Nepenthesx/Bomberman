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

public:enum Level
    {
        First,
        Second,
        Third
    };

private:
    static QList<GameObject*> gameObjects; //POWINNO BYĆ STATYCZNE, ABY USUWANE OBIEKTY USUWAŁY SIĘ Z LISTY!!!
    static QList<GraphicObject*> graphicObjects;
    static QWidget* widgetParent;

    static int globalScale;
    int frameCount = 0;
    float frameInterval;
    QTimer* timer;

    Level level;

    void createFirstLevel();
    void createSecondLevel();
    void createThirdLevel();

public:
    GameManager(int globalScale, float frameInterval = 1000, Level level = GameManager::First, QWidget* widgetParent = nullptr);

    static int getGlobalScale();
    static void setGlobalScale(int scale);

    int getFrameCount();
    float getFrameInterval();
    void setFrameInterval(float frameInterval);

    Level getLevel();
    void setLevel(Level level);

    static void addObject(GameObject* object);
    static void removeObject(GameObject* object);

    void startLevel();
    void endLevel();

    static void createBomb(Bomber* owner, QVector<int> position, int explosionPower, Bomber::BombType bombType);
    static void createFloor(QVector<int> position);

    static QList<GameObject*> getObjectsInRange(GameObject* object, int range);
    static QList<GameObject*> getObjectsInContact(QVector<int> objectPosition, QVector<int> objectSize);
    static QSet<GameObject*> getObjectsInContactArea(QVector<int> basePosition, QSet<QVector<int>> relativePositions, QVector<int> objectSize);
    static bool checkContact(QVector<int> firstObjectPosition, QVector<int> firstObjectSize, QVector<int> secondObjectPosition, QVector<int> secondObjectSize);

public slots:
    void updateGame(); //DODAĆ TIMER
};

#endif // GAMEMANAGER_H
