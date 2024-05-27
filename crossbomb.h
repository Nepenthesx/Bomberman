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
     * \param owner Twórca bomby
     * \param position Pozycja
     * \param size Rozmiar
     * \param explosionPower Zasięg rażenia
     * \param lifetime Czas do eksplozji, domyślnie =4000ms
     * \param durability Wytrzymałość, domyślnie =1
     */
    CrossBomb(Bomber* owner, QVector<int> position, QVector<int> size, int explosionPower, int lifetime = 4000, int durability = 1);
};

#endif // CROSSBOMB_H
