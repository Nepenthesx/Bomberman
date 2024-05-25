#ifndef ITEM_H
#define ITEM_H

#include "dynamicobject.h"
#include "temporaryobject.h"

/*!
 * \brief Przedmiot leżący na planszy gry
 */
class Item : public DynamicObject, public TemporaryObject
{
public:
    /*!
     * \brief Konstruktor przedmiotu
     * \param Pozycja
     * \param Rozmiar
     * \param Czas istnienia przedmiotu
     * \param Wytrzymałość
     */
    Item(QVector<int> position, QVector<int> size, int lifetime, int durability);

    /*!
     * \brief Aktualizacja stanu obiektu poprzez sprawdzenie wytrzymałości i czasu istnienia
     */
    void update() override;
    /*!
     * \brief Usunięcie przedmiotu w wyniku utraty całej wytrzymałości
     */
    void onDurabilityLoss() override;
    /*!
     * \brief Wymuszenie na przedmiocie utraty całej wytrzymałości w wyniku skończenia się czasu jego istnienia
     */
    void onTimeout() override;
};

#endif // ITEM_H
