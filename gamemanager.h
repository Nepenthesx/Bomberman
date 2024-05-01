#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "graphicsmanager.h"
#include "gameobject.h"
#include "graphicobject.h"

#include <QObject>
#include <QWidget>
#include <QList>
#include <QTimer>
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
    QList<GraphicObject*> graphicObjects;

    static int globalScale;
    int frameCount = 0;
    float frameInterval;
    QTimer* timer;

    Level level;
    GraphicsManager* graphicsManager; //powinien być tylko jeden

    void createFirstLevel(QWidget* parent = nullptr);
    void createSecondLevel(QWidget* parent = nullptr);
    void createThirdLevel(QWidget* parent = nullptr);

public:
    GameManager(int globalScale, float frameInterval = 1000, Level level = GameManager::First);

    static int getGlobalScale();
    static void setGlobalScale(int scale);

    int getFrameCount();
    float getFrameInterval();
    void setFrameInterval(float frameInterval);

    Level getLevel();
    void setLevel(Level level);

    void addObject(GameObject* object);
    void removeObject(GameObject* object);

    static QList<GameObject*> getObjectsInRange(GameObject* object, int range);
    static QList<GameObject*> getObjectsInContact(QVector<int> objectPosition, QVector<int> objectSize);
    static bool checkContact(QVector<int> firstObjectPosition, QVector<int> firstObjectSize, QVector<int> secondObjectPosition, QVector<int> secondObjectSize);
    //QList<GameObject*> getObjectsInContact(GameObject* object);
    //bool checkContact(GameObject* firstObject, GameObject* secondObject);

    void startLevel(QWidget* parent = nullptr);
    void endLevel();

public slots:
    void updateGame(); //DODAĆ TIMER
};

#endif // GAMEMANAGER_H