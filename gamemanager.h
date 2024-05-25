#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "gameobject.h"
#include "graphicobject.h"
#include "bomber.h"

#include <QObject>
#include <QWidget>
#include <QList>
#include <QSet>
#include <QTimer>
#include <QDebug>
#include <QVector>

/*!
 * \brief Silnik gry, zarządzający wszystkimi obiektami i grafiką
 */
class GameManager : public QObject
{
    Q_OBJECT

private:
    /*!
     * \brief Konstruktor managera gry
     * \param Podstawowa skala wielkości obiektów
     * \param Okno w którym wyświetlana jest grafika
     * \param Czas między kolejnymi klatkami
     */
    GameManager(int globalScale, QWidget* window, float frameInterval);
    /*!
     * \brief Obecnie istniejący manager gry
     */
    static GameManager* instance;

    /*!
     * \brief Lista obecnych w grze obiektów
     * \see GameObject
     */
    static QList<GameObject*> gameObjects;
    /*!
     * \brief Lista obecnych w grze graficznych wizerunków
     * \see GraphicObject
     */
    static QList<GraphicObject*> graphicObjects;
    /*!
     * \brief Okno w którym wyświetlana jest grafika
     */
    static QWidget* window;

    /*!
     * \brief Podstawowa skala będąca odniesieniem rozmiaru istniejących w grze obiektów
     */
    static int globalScale;
    /*!
     * \brief Czas między kolejnymi klatki gry, czyli aktualizacjami stanu obiektów
     */
    static float frameInterval;
    /*!
     * \brief Liczba klatek które odbyły się do obecnego momentu
     */
    static int frameCount;
    /*!
     * \brief Obiekt odpowiadający za cykliczne wykonywania się aktualizacji obiektów
     */
    static QTimer* timer;

    //GameManager(const GameManager&) = delete;
    //GameManager& operator=(const GameManager&) = delete;

    /*!
     * \brief Usunięcie wskazanego obiektu z systemu gry
     * \param Obiekt gry do usunięcia
     *
     * Usunięce obiektu odbywa się poprzez odnalazienie go na liście istniejących obiektów, następnie
     *  wyszukanie wśród listy graficznych obiektów takiego graficznego obiektu, który stanowi
     *  graficzny wizerunek usuwanego obiektu. Najpier usuwany jest graficzny wizerunek, następnie
     *  sam obiekt.
     */
    void removeObject(GameObject* object);

public:
    //GameManager(int globalScale, QWidget* window, float frameInterval = 1000);
    /*!
     * \brief Utworzenie singletowego managera gry
     * \param Podstawowa skala wielkości obiektów
     * \param Okno w którym wyświetlana jest grafika
     * \param Czas między kolejnymi klatkami
     * \return Utworzony manager gry
     *
     * Manager gry jest singletonem, a więc jest możliwe utworzenie tego obiektu tylko raz
     */
    static GameManager* getInstance(int globalScale, QWidget* window, float frameInterval = 1000);

    static int getGlobalScale();
    static void setGlobalScale(int scale);

    static int getFrameCount();
    static float getFrameInterval();
    static void setFrameInterval(float frameInterval);

    /*!
     * \brief Utworzenie odpowiednich obiektów, które będą budować początkową planszę poziomu
     */
    static void startLevel();
    /*!
     * \brief Usunięcie wszystkich obiektów i grafik pozostawiając puste okno
     */
    static void endLevel();


    /*!
     * \brief Utworzenie obiektu podłogi
     * \param Pozycja
     * \see FloorTile
     */
    static void createFloorTile(QVector<int> position);
    /*!
     * \brief Utworzenie obiektu kamienia
     * \param Pozycja
     * \see RockTile
     */
    static void createRockTile(QVector<int> position);
    /*!
     * \brief Utworzenie obiektu ściany
     * \param Pozycja
     * \see WallTile
     */
    static void createWallTile(QVector<int> position);
    /*!
     * \brief Utworzenie obiektu gracza
     * \param Pozycja
     * \param Szybkość ruchu
     * \see Player
     */
    static void createPlayer(QVector<int> position, int speed);
    /*!
     * \brief Utworzenie obiektu przeciwnika
     * \param Pozycja
     * \param Szybkość ruchu
     * \see Enemy
     */
    static void createEnemy(QVector<int> position, int speed);
    /*!
     * \brief Utworzenie obiektu bomby
     * \param Pozycja
     * \param Twórca bomby
     * \param Zasięg rażenia
     * \param Kształt eksplozji bomby
     * \see Bomb
     */
    static void createBomb(QVector<int> position, Bomber* owner, int explosionPower, Bomber::BombType bombType);
    /*!
     * \brief Utworzenie obiektu ulepszenia kształtu bomby
     * \param Pozycja
     * \see BombTypeUpgrade
     */
    static void createBombTypeUpgrade(QVector<int> position);
    /*!
     * \brief Utworzenie obiektu ulepszenia zasięgu rażenia bomby
     * \param Pozycja
     * \see BombPowerUpgrade
     */
    static void createBombPowerUpgrade(QVector<int> position);
    /*!
     * \brief Utworzenie obiektu ulepszenia ilości stawianych bomb
     * \param Pozycja
     * \see BombCountUpgrade
     */
    static void createBombCountUpgrade(QVector<int> position);


    //static QList<GameObject*> getObjectsInRange(GameObject* object, int range);
    /*!
     * \brief Znalezienie wszystkich obiektów które są w kontakcie z danym obiektem
     * \param Pozycja badanego obiektu
     * \param Rozmiar badanego obiektu
     * \return Lista obiektów będących w kontakcie z danym obiektem
     * \see Funkcja checkContact
     *
     * Znalezienie obiektów odbywa się poprzez iteracje przez całą listę obecnie istniejących obiektów
     * gry i sprawdzenie funkcją checkContact, czy ten obiekt z listy zachodzi powierzchnią z badanym
     * obiektem. Zwracane są wszystkie obiekty z listy istniejących obiektów, które wykazały kontakt.
     */
    static QList<GameObject*> getObjectsInContact(QVector<int> objectPosition, QVector<int> objectSize);
    /*!
     * \brief Znalezienie wszystkich obiektów które są w kontakcie z danym obiektem w wskazanym przez niego obszarze
     * \param Pozycja badanego obiektu
     * \param Zbiór badanych pozycji określonych względem podstawowej pozycji obiektu
     * \param Rozmiar badanego obiektu
     * \return Stos obiektów będących w kontakcie z danym obiektem
     * \see Funkcja checkContact
     * \see Funckja getObjectsInContact
     *
     * Znalezienie obiektów odbywa się poprzez iteracje przez listę pozycji zawartych w relativePosition.
     * Dla poszczególnej pozycji sprawdzane są funkcją checkContact wszystkie istniejące w grze obiekty,
     * które zachodzą powierzchnią z tą pozycją. Zamiana listy na stos ma zapobiedz powieleniu się tych
     * samych obiektów. Pozycje względne określone są w skali globalnej managera globalScale
     */
    static QSet<GameObject*> getObjectsInContactArea(QVector<int> basePosition, QSet<QVector<int>> relativePositions, QVector<int> objectSize);
    /*!
     * \brief Sprawdza zachodzenie się powierzchni dwóch wskazanych obiektów
     * \param Pozycja pierwszego obiektu
     * \param Rozmiar pierwszego obiektu
     * \param Pozycja drugiego obiektu
     * \param Rozmiar drugiego obiektu
     * \return Informacja czy wskazane obiekty zachodzą się powierzchniami
     */
    static bool checkContact(QVector<int> firstObjectPosition, QVector<int> firstObjectSize, QVector<int> secondObjectPosition, QVector<int> secondObjectSize);

private slots:
    /*!
     * \brief Aktualizowanie stanu wszystkich istniejących obiektów na liście managera
     * \see GameObject
     * \see GraphicObject
     *
     * Aktualizowanie obiektów opiera się o wywołanie funkcji update() każdego obiektu typu GameObject
     * na liście obiektów managera gameObjects. Obiekty o fladze isActive=0 nie wykonują aktualizacji,
     * a po wykonaniu się iteracji całej listy te są następnie usuwane funckją removeObject. Następnie
     * iterowana jest lista wizerunków graficznych obiektów graphicObjects i dla każdego elementu wykonywana
     * jest funkcja update() będąca polem QWidget, co odpowiada za ponowne narysowanie się obiektu.
     * Funkcja wykonywana jest cyklicznie co czas zawarty w frameInterval i jej wykonanie określa się jako
     * klatkę działania gry
     */
    void updateGame();
};

#endif // GAMEMANAGER_H
