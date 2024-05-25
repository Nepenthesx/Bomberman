#ifndef MOVABLEOBJECT_H
#define MOVABLEOBJECT_H

#include <QVector>

/*!
 * \brief Obiekt zdolny się poruszać
 */
class MovableObject
{
private:
    /*!
     * \brief Szybkość ruchu określająca wartość zmiany pozycji w jednej klatce gry
     */
    int speed;

protected:
    int getSpeed();
    void setSpeed(int speed);

public:
    /*!
     * \brief Konstruktor obiektu ruchomego
     * \param Szybkość ruchu
     */
    MovableObject(int speed);
    /*!
     * \brief Ruszenie się obiektu
     * \param Docelowa pozycja na którą obiekt się ruszy
     */
    virtual void move(QVector<int> nextPosition) = 0;
};

#endif // MOVABLEOBJECT_H
