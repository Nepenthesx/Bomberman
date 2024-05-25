#ifndef CROSSBOMB_H
#define CROSSBOMB_H

#include "bomb.h"

/*!
 * \brief Rodzaj bomby, której zasięg rażenia jest w kształcie krzyża
 */
class CrossBomb : public Bomb
{
public:
    /*!
     * \brief Konstruktor bomby krzyżowej
     * \param Twórca bomby
     * \param Pozycja
     * \param Rozmiar
     * \param Zasięg rażenia
     * \param Czas do eksplozji
     * \param Wytrzymałość
     */
    CrossBomb(Bomber* owner, QVector<int> position, QVector<int> size, int explosionPower, int lifetime = 4000, int durability = 1);
};

#endif // CROSSBOMB_H
