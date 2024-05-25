#ifndef PLAYER_H
#define PLAYER_H

#include "bomber.h"
#include <windows.h> //do wykrywania przycisków
#include <QVector>

/*!
 * \brief Postać sterowana przez użytkownika
 */
class Player : public Bomber
{

public:
    /*!
     * \brief Konstruktor gracza
     * \param Pozycja
     * \param Rozmiar
     * \param Szybkość ruchu
     * \param Wytrzymałość
     * \param Maksymalna ilość postawionych jednocześnie bomb
     * \param Zasięg rażenia stawianych bomb
     * \param Kształt eksplozji stawianych bomb
     */
    Player(QVector<int> position, QVector<int> size, int speed, int durability = 3, int maxBombCount = 1, int bombPower = 1, Bomber::BombType bombType = Bomber::Cross);

    /*!
     * \brief Aktualizacja stanu obiektu poprzez sprawdzenie wytrzymałości i ruch
     */
    void update() override;
    /*!
     * \brief Dokonanie przemieszczenia na wskazaną przez użytkownika pozycję
     * \param Pozycja na którą zamierza przemieścić się gracz
     *
     * Wskazanie następnej pozycji gracza odbywa się poprzez odpowiedni przycisk klawiatury
     * LeftArrow - pozycja na lewo od obecnej
     * RightArrow - pozycja na prawo od obecnej
     * UpArrow - pozycja w górę od obecnej
     * DownArrow - pozycja w dół od obecnej
     * Gracz nie jest w stanie wejść na obiekty typu RockTile i WallTile
     */
    void move(QVector<int> nextPosition) override;
    /*!
     * \brief Usunięcie gracza w wyniku utraty całej wytrzymałości i zakończenie poziomu gry
     */
    void onDurabilityLoss() override;

    /*!
     * \brief Zebranie przez gracza przedmiotu umieszczonego na planszy gry
     *
     * Gracz jest w stanie zebrać obiekty typu BombCountUpgrade, BombTypeUpgrade i BombPowerUpgrade
     */
    void pickItem();

};

#endif // PLAYER_H
