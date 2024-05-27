#ifndef WALLTILE_H
#define WALLTILE_H

#include "staticobject.h"

/*!
 * \brief Ściana blokująca ruch obiektów i niemożliwa do zniszczenia
 */
class WallTile : public StaticObject
{
public:
    /*!
     * \brief Konstruktor ściany
     * \param position Pozycja
     * \param size Rozmiar
     */
    WallTile(QVector<int> position, QVector<int> size);
    /*!
     * \brief Aktualizacja stanu obiektu - ściana nie posiada żadnych aktywności
     */
    void update() override;
};

#endif // WALLTILE_H
