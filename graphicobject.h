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


class GraphicObject : public QWidget
{
    Q_OBJECT

private:
    GameObject* gameObject;
    QPixmap picture;
    int drawingPriority;

public:
    GraphicObject(GameObject* gameObject, std::string graphicRelativePath, QWidget* parent, int drawingPriority);

    QPixmap getPicture();
    void setPicture(std::string graphicRelativePath);
    int getDrawingPriority();
    void setDrawingPriority(int drawingPriority);
    GameObject* getGameObject();

    static void sortByPriority(QList<GraphicObject*> objectsList);

private:
    void paintEvent(QPaintEvent*);

};

#endif // GRAPHICOBJECT_H
