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
     * \param Twórca bomby
     * \param Pozycja
     * \param Rozmiar
     * \param Zasięg rażenia
     * \param Czas do eksplozji
     * \param Wytrzymałość
     */
    SquareBomb(Bomber* owner, QVector<int> position, QVector<int> size, int explosionPower, int lifetime = 4000, int durability = 1);
};

#endif // SQUAREBOMB_H
