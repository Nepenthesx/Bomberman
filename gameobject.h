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


public:enum PivotLocation
    {
        UpLeft,
        Center
    };

protected:
    Vector2i position;
    QPixmap picture;
    float relativeScale;
    PivotLocation pivotLocation;

public:
    Vector2i getPosition();
    void setPosition(int x, int y);
    QPixmap getPicture();
    void setPicture(QPixmap pic);
    void setPicture(string relativePath);
    float getRelativeScale();
    void setRelativeScale(float relativeScaleValue);
    PivotLocation getPivotLocation();
    void setPivotLocation(PivotLocation pivot);

signals:
};

#endif // GAMEOBJECT_H
