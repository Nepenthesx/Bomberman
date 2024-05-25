#ifndef FLOORTILE_H
#define FLOORTILE_H

#include "staticobject.h"

/*!
 * \brief Podłoga, czyli podstawowy obiekt planszy poziomu, po którym mogą swobodnie poruszać się postacie
 */
class FloorTile : public StaticObject
{
public:
    /*!
     * \brief Konstruktor podłogi
     * \param Pozycja
     * \param Rozmiar
     */
    FloorTile(QVector<int> position, QVector<int> size);
    /*!
     * \brief Aktualizacja stanu obiektu - podłoga nie posiada żadnych aktywności
     */
    void update() override;
};

#endif // FLOORTILE_H
