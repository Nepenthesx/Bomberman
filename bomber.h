#ifndef BOMBER_H
#define BOMBER_H

#include "character.h"

/*!
 * \brief Postać mogąca stawiać na podłodze bomby
 * \see Bomb
 */
class Bomber : public Character
{
/*!
 * \brief Rodzaj kształtu ekplozji stawianej bomby
 */
public:enum BombType
    {
        Cross,
        Square
    };

private:
    /*!
     * \brief Obecna liczba postawionych bomb
     */
    int bombCount;
    /*!
     * \brief Maksymalna liczba bomb mogąca być jednocześnie postawiona na ziemi przez bombera
     */
    int maxBombCount;
    /*!
     * \brief Zasięg rażenia stawianych bomb
     */
    int bombPower;
    /*!
     * \brief Kształ eksplozji stawianych bomb
     */
    Bomber::BombType bombType;

protected:
    int getMaxBombCount();
    void setMaxBombCount(int maxBombCount);
    int getBombPower();
    void setBombPower(int bombPower);
    Bomber::BombType getBombType();
    void setBombType(Bomber::BombType bombType);

public:
    /*!
     * \brief Konstruktor bombera
     * \param Pozycja
     * \param Rozmiar
     * \param Szybkość ruchu
     * \param Wytrzymałość
     * \param Maksymalna ilość postawionych jednocześnie bomb
     * \param Zasięg rażenia stawianych bomb
     * \param Kształt eksplozji stawianych bomb
     */
    Bomber(QVector<int> position, QVector<int> size, int speed, int durability, int maxBombCount, int bombPower, Bomber::BombType bombType);
    virtual void update() = 0;
    virtual void onDurabilityLoss() = 0;
    virtual void move(QVector<int> nextPosition) = 0;
    /*!
     * \brief Tworzenie obiektu Bomb na ziemi pod postacią
     */
    void placeBomb();

    int getBombCount();
    /*!
     * \brief Zwiększenie ilości obecnie posiadanych bomb o 1
     */
    void incrementBombCount();
    /*!
     * \brief Zmniejszenie ilości obecnie posiadanych bomb o 1
     */
    void decrementBombCount();
};

#endif // BOMBER_H
