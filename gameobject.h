#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QVector>
#include <QDebug>

/*!
 * \brief Ogólny obiekt istniejący w grze
 * \see GameManager
 */
class GameObject
{
private:
    /*!
     * \brief Pozycja, czyli położenie obiektu na macierzy planszy gry
     */
    QVector<int> position;
    /*!
     * \brief Rozmiar stanowiący szerokość i wysokość prostokąta który reprezentuje wielkość obiektu
     */
    QVector<int> size;
    /*!
     * \brief Flaga wskazująca zdolność obiektu do istnienia w grze i wykonywania aktualizacji
     */
    bool isActive;

public:
    /*!
     * \brief Konstruktor obiektu gry
     * \param Pozycja
     * \param Rozmiar
     */
    GameObject(QVector<int> position, QVector<int> size);
    /*!
     * \brief Destruktor obiektu gry
     */
    virtual ~GameObject();

    /*!
     * \brief Aktualizacja stanu obiektu stanowiąca podstawową funkcję aktywności
     */
    virtual void update() = 0;

    QVector<int> getPosition();
    void setPosition(QVector<int> position);
    QVector<int> getSize();
    void setSize(QVector<int> size);
    /*!
     * \brief Zwraca czy obiekt wykazuje aktywność
     * \return Aktywność obiektu
     */
    bool checkActivity();

    /*!
     * \brief Ustawia aktywność obiektu na 0 czyli brak aktywności
     */
    void desactive();

};

#endif // GAMEOBJECT_H
