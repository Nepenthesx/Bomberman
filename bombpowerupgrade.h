#ifndef BOMBPOWERUPGRADE_H
#define BOMBPOWERUPGRADE_H

#include "item.h"

/*!
 * \brief Ulepszenie po którym postać może stawiać bomby o większej sile rażenia
 */
class BombPowerUpgrade : public Item
{
public:
    /*!
     * \brief Konstruktor ulepszenia ilości bomb
     * \param Pozycja
     * \param Rozmiar
     * \param Czas po którym ulepszenie znika, domyślnie =8000ms
     * \param Wytrzymałość, domyślnie =1
     */
    BombPowerUpgrade(QVector<int> position, QVector<int> size, int lifetime = 8000, int durability = 1);
};

#endif // BOMBPOWERUPGRADE_H
