#ifndef ROCKTILE_H
#define ROCKTILE_H

#include "dynamicobject.h"
#include <QDebug>

/*!
 * \brief Kamień, czyli ściana możliwa do zniszczenia
 */
class RockTile : public DynamicObject
{
public:
    /*!
     * \brief Konstruktor kamienia
     * \param Pozycja
     * \param Rozmiar
     * \param Wytrzymałość
     */
    RockTile(QVector<int> position, QVector<int> size, int durability = 1);

    /*!
     * \brief Aktualizacja stanu obiektu poprzez sprawdzenie wytrzymałości
     */
    virtual void update() override;
    /*!
     * \brief Usunięcie kamienia w wyniku utraty całej wytrzymałości i zamienie go w podłogę FloorTile
     * \see FloorTile
     */
    virtual void onDurabilityLoss() override;
};

#endif // ROCKTILE_H
