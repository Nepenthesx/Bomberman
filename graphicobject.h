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
    QPixmap picture;

public:
    GraphicObject(GameObject* gameObject, std::string graphicRelativePath, QWidget* parent);

    GameObject* gameObject;
    QPixmap getPicture();
    void setPicture(QPixmap picture);
    void setPicture(std::string graphicRelativePath);

protected:
    void paintEvent(QPaintEvent*);

};

#endif // GRAPHICOBJECT_H
