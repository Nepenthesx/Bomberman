#ifndef BOMB_H
#define BOMB_H

#include "dynamicobject.h"
#include "temporaryobject.h"
#include "bomber.h"
#include <QSet>

/*!
 * \brief Obiekt uszkadzający wszystkie obiekty zniszczalne na sąsiednich polach
 * \see DynamicObject
 */
class Bomb : public DynamicObject, public TemporaryObject
{

private:
    /*!
     * \brief Twórca bomby
     */
    Bomber* owner;
    /*!
     * \brief Zasięg rażenia obiektów, czyli zadawania im obrażeń
     */
    int explosionPower;
    /*!
     * \brief Dokonywanie procesu zadawania obrażeń sąsiadom
     */
    void explode();

protected:
    /*!
     * \brief Pozycje sąsiadów względem bomby w skali globalScale
     * \see GameManager globalScale
     */
    QSet<QVector<int>> relativeExplosionPositions;

public:
    /*!
     * \brief Konstruktor bomby
     * \param owner Twórca bomby
     * \param position Pozycja
     * \param size Rozmiar
     * \param explosionPower Zasięg rażenia
     * \param lifetime Czas do eksplozji
     * \param durability Wytrzymałość
     */
    Bomb(Bomber* owner, QVector<int> position, QVector<int> size, int explosionPower, int lifetime, int durability);

    void update() override;
    void onDurabilityLoss() override;
    void onTimeout() override;
};

#endif // BOMB_H
