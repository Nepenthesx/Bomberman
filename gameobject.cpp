#include "gameobject.h"

#include <Eigen/Dense>
#include <QImage>
#include <QImageReader>
#include <QPixmap>
#include <QDebug>
#include <QDir>
#include <iostream>

using namespace std;
using namespace Eigen;

Vector2i GameObject::getPosition()
{
    return position;
}

void GameObject::setPosition(int x, int y)
{
    Vector2i pos(x, y);
    position = pos;
}

QPixmap GameObject::getPicture()
{
    return picture;
}

void GameObject::setPicture(QPixmap pic)
{
    picture = pic;
}

void GameObject::setPicture(string relativePath)
{
    QDir dir(QDir::currentPath());
    string spath = "../PJC" + relativePath;
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
