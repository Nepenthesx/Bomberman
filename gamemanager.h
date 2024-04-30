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
    QList<GameObject*> gameObjects; //POWINNO BYĆ STATYCZNE, ABY USUWANE OBIEKTY USUWAŁY SIĘ Z LISTY!!!
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
    void checkContact(GameObject* object);

    void startLevel(QWidget* parent = nullptr);
    void endLevel();

public slots:
    void updateGame(); //DODAĆ TIMER
};

#endif // GAMEMANAGER_H
