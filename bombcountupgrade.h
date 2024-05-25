#ifndef BOMBCOUNTUPGRADE_H
#define BOMBCOUNTUPGRADE_H

#include "item.h"

/*!
 * \brief Ulepszenie po którym postać może stawiać więcej bomb jednocześnie
 */
class BombCountUpgrade : public Item
{
public:
    /*!
     * \brief Konstruktor ulepszenia ilości bomb
     * \param Pozycja
     * \param Rozmiar
     * \param Czas po którym ulepszenie znika, domyślnie =8000ms
     * \param Wytrzymałość, domyślnie =1
     */
    BombCountUpgrade(QVector<int> position, QVector<int> size, int lifetime = 8000, int durability = 1);
};

#endif // BOMBCOUNTUPGRADE_H
