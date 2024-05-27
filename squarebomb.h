#ifndef SQUAREBOMB_H
#define SQUAREBOMB_H

#include "bomb.h"

/*!
 * \brief Rodzaj bomby, której zasięg rażenia jest w kształcie kwadratu
 */
class SquareBomb : public Bomb
{
public:
    /*!
     * \brief Konstruktor bomby kwadratowej
     * \param owner Twórca bomby
     * \param position Pozycja
     * \param size Rozmiar
     * \param explosionPower Zasięg rażenia
     * \param lifetime Czas do eksplozji, domyślnie =4000ms
     * \param durability Wytrzymałość, domyślnie =1
     */
    SquareBomb(Bomber* owner, QVector<int> position, QVector<int> size, int explosionPower, int lifetime = 4000, int durability = 1);
};

#endif // SQUAREBOMB_H
