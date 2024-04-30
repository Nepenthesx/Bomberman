#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H

#include "gameobject.h"
#include <QWidget>
#include <QObject>
#include <QImage>
#include <QPixmap>
#include <QPaintEvent>


class GraphicObject : public QWidget
{
    Q_OBJECT

private:
    QPixmap picture;

public:
    GraphicObject(GameObject* gameObject, std::string graphicRelativePath, QWidget* parent);

    GameObject* gameObject;
    QPixmap getPicture();
    void setPicture(QPixmap pic);
    void setPicture(std::string graphicRelativePath);

protected:
    void paintEvent(QPaintEvent*);

};

#endif // GRAPHICOBJECT_H
