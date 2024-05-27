#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

/*!
 * \brief Przeciwnik, czyli postać mogąca ranić gracza i dążąca do jego zniszczenia
 */
class Enemy : public Character
{
private:
    /*!
     * \brief Względne pozycje obiektów będących sąsiadami przeciwnika
     */
    QSet<QVector<int>> relativeClosePositions;

public:
    /*!
     * \brief Konstruktor przeciwnika
     * \param position Pozycja
     * \param size Rozmiar
     * \param speed Szybkość ruchu
     * \param durability Wytrzymałość, domyślnie =3
     */
    Enemy(QVector<int> position, QVector<int> size, int speed, int durability = 3);

    /*!
     * \brief Aktualizacja stanu obiektu poprzez sprawdzenie wytrzymałości i ruch
     */
    void update() override;
    /*!
     * \brief Dokonanie przemieszczenia na wskazaną przez SI przeciwnika pozycję
     * \param nextPosition Pozycja na którą zamierza przemieścić się przeciwnik
     *
     * Wskazanie następnej pozycji przeciwnika odbywa się poprzez analizę sąsiednich obiektów
     *  zawartych w relativeClosePosition. Piorytetem jest sąsiad w postaci Player, następnie
     *  FloorTile. Jeśli możliwe są 2 pozycje o tym samym piorytecie, wybór jednej z nich
     *  odbywa się losowo.
     * Przeciwnik nie jest w stanie wejść na obiekty typu RockTile i WallTile
     */
    void move(QVector<int> nextPosition) override;
    /*!
     * \brief Usunięcie przeciwnika w wyniku utraty całej wytrzymałości
     */
    void onDurabilityLoss() override;
};

#endif // ENEMY_H
