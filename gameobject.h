#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QObject>
#include <QImage>
#include <QPixmap>

#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

class GameObject : public QObject
{
    Q_OBJECT

private:
    Vector2i position;
    QPixmap picture;

public:
    Vector2i getPosition();
    void setPosition(int x, int y);
    QPixmap getPicture();
    void setPicture(QPixmap pic);
    void setPicture(string relativePath);

signals:
};

#endif // GAMEOBJECT_H
