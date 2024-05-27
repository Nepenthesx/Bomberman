#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "gameobject.h"
#include <QVector>

/*!
 * \brief Obiekt niepodlegający zniszczeniu
 */
class StaticObject : public GameObject
{
public:
    /*!
     * \brief Konstruktor obiektu statycznego
     * \param position Pozycja
     * \param size Rozmiar
     */
    StaticObject(QVector<int> position, QVector<int> size);
    virtual void update() = 0;
};

#endif // STATICOBJECT_H
