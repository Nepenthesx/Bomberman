#include "graphicobject.h"

#include "gameobject.h"
#include "gamemanager.h"
#include <QWidget>
#include <QPainter>
#include <QList>
#include <QDebug>
#include <QVector>
#include <QDir>
#include <QImageReader>


GraphicObject::GraphicObject(GameObject* gameObject, std::string graphicRelativePath, QWidget* parent) : QWidget (parent)
{
    this->gameObject = gameObject;
    setPicture(graphicRelativePath);
}

QPixmap GraphicObject::getPicture()
{
    return picture;
}

void GraphicObject::setPicture(QPixmap pic)
{
    picture = pic;
}

void GraphicObject::setPicture(std::string graphicRelativePath)
{
    QDir dir(QDir::currentPath());
    std::string spath = "../.." + graphicRelativePath;
    QString qpath = QString::fromStdString(spath);
    qpath = dir.absoluteFilePath(qpath);

    QImageReader reader(qpath);
    reader.setDecideFormatFromContent(true);

    QImage img = reader.read();
    if (!img.isNull())
        picture = QPixmap::fromImage(img);
    else
        qDebug() << "Error to load file";
}

void GraphicObject::paintEvent(QPaintEvent*)
{
    QVector<int> position = gameObject->getPosition();
    QVector<int> size = gameObject->getSize();
    setGeometry(position[0], position[1], size[0], size[1]);

    QPainter painter(this);


    QRect rect(0, 0, size[0], size[1]);
    painter.drawPixmap(rect, picture);
}
