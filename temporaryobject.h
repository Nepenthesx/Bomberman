#ifndef TEMPORARYOBJECT_H
#define TEMPORARYOBJECT_H

#include <QObject>
#include <QTimer>

/*!
 * \brief Obiekt wykonujący akcję po upłynięciu czasu
 */
class TemporaryObject : public QObject
{
    Q_OBJECT

private:
    /*!
     * \brief Obiekt odpowiadający za liczenie czasu do wystąpienia akcji
     */
    QTimer* timer;
    /*!
     * \brief Określenie czy czas do wykonania akcji upłynął
     */
    bool isTimeout;

    /*!
     * \brief Uruchomienie timera
     * \param Czas do wykonania akcji
     */
    void setTimer(int lifetime);

protected:
    /*!
     * \brief Sprawdzenie czy upłynął czas do wykonania akcji
     * \return Czy czas upłynął
     */
    bool checkTimeout();

public:
    /*!
     * \brief Konstruktor obiektu czasowego
     * \param Czas do wykonania akcji
     */
    TemporaryObject(int lifetime);
    /*!
     * \brief Zainicjalizowanie akcji po upłynięciu określonego czasu
     */
    virtual void onTimeout() = 0;

private slots:
    /*!
     * \brief Wskazanie na upłynięcie wyznaczonego czasu
     */
    void changeTimeoutStatus();
};

#endif // TEMPORARYOBJECT_H
