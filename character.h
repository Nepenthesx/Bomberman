#ifndef CHARACTER_H
#define CHARACTER_H

#include "dynamicobject.h"
#include "movableobject.h"

#include <QVector>
#include <QDebug>

/*!
 * \brief Postać mogąca poruszać się po planszy poziomu
 */
class Character : public DynamicObject, public MovableObject
{
public:
    /*!
     * \brief Konstruktor postać
     * \param position Pozycja
     * \param size Rozmiar
     * \param speed Szybkość ruchu
     * \param durability Wytrzymałość
     */
    Character(QVector<int> position, QVector<int> size, int speed, int durability);

    virtual void update() = 0;
    virtual void onDurabilityLoss() = 0;
    virtual void move(QVector<int> nextPosition) = 0;
};

#endif // CHARACTER_H
