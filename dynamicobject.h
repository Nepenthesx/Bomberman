#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H

#include "gameobject.h"
#include <QVector>

/*!
 * \brief Obiekt mogący być zniszczony w wyniku interakcji z innymi obiektami
 */
class DynamicObject : public GameObject
{
private:
    /*!
     * \brief Wytrzymałość, czyli ilość obrażeń które może przyjąć obiekt przed jego zniszczeniem
     */
    int durability;

protected:
    int getDurability();
    void setDurability(int durability);

public:
    /*!
     * \brief Konstruktor obiektu zniszczalnego
     * \param position Pozycja
     * \param size Rozmiar
     * \param durability Wytrzymałość
     */
    DynamicObject(QVector<int> position, QVector<int> size, int durability);
    virtual void update() = 0;
    /*!
     * \brief Zainicjalizowanie akcji w wyniku utraty całej wytrzymałości
     */
    virtual void onDurabilityLoss() = 0;
    /*!
     * \brief Przyjęcie przez obiekt obrażeń skutkujące obniżeniem jego wytrzymałości o wartość obrażeń
     * \param damage Wartość obrażeń
     */
    void takeDamage(int damage);
};

#endif // DYNAMICOBJECT_H
