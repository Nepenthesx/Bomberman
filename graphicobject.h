#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H

#include "gameobject.h"
#include <QWidget>
#include <QObject>
#include <QImage>
#include <QPixmap>
#include <QPaintEvent>
#include <QPainter>
#include <QList>
#include <QDebug>
#include <QVector>
#include <QDir>
#include <QImageReader>


/*!
 * \brief Graficzny wizerunek obiektu gry
 */
class GraphicObject : public QWidget
{
    Q_OBJECT

private:
    /*!
     * \brief Obiekt gry którego wizerunkiem graficznym jest ten obiekt
     */
    GameObject* gameObject;
    /*!
     * \brief Grafika
     */
    QPixmap picture;
    /*!
     * \brief Priorytet w głębokości rysowania
     * Obiekty o wyższym priorytecie rysowane są nad obiektami o niższym
     */
    int drawingPriority;

public:
    /*!
     * \brief Konstruktor obiektu graficznego
     * \param Obiekt gry
     * \param Ścieżka do pliku z grafiką
     * \param Okno gry
     * \param Priorytet rysowania
     */
    GraphicObject(GameObject* gameObject, std::string graphicRelativePath, QWidget* parent, int drawingPriority);

    QPixmap getPicture();
    /*!
     * \brief Ustawia grafikę do rysowania na podstawie ścieżki pliku graficznego
     * \param Ścieżka do pliku z grafiką względem pliku "build"
     */
    void setPicture(std::string graphicRelativePath);
    int getDrawingPriority();
    void setDrawingPriority(int drawingPriority);
    GameObject* getGameObject();

    /*!
     * \brief Sortowanie listy obiektów graficznych po ich priorytecie rysowania
     * \param Lista obiektów graficzny
     */
    static void sortByPriority(QList<GraphicObject*> objectsList);

private:
    /*!
     * \brief Funkcja rysowania wbudowana w obiekt typu QWidget
     */
    void paintEvent(QPaintEvent*);

};

#endif // GRAPHICOBJECT_H
