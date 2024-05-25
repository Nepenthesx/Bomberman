#ifndef BOMBTYPEUPGRADE_H
#define BOMBTYPEUPGRADE_H

#include "item.h"

/*!
 * \brief Ulepszenie po którym postać może stawiać bomby o innym kształcie eksplozji
 */
class BombTypeUpgrade : public Item
{
public:
    /*!
     * \brief Konstruktor ulepszenia ilości bomb
     * \param Pozycja
     * \param Rozmiar
     * \param Czas po którym ulepszenie znika, domyślnie =8000ms
     * \param Wytrzymałość, domyślnie =1
     */
    BombTypeUpgrade(QVector<int> position, QVector<int> size, int lifetime = 8000, int durability = 1);
};

#endif // BOMBTYPEUPGRADE_H
