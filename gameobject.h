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
    //int globalScale;
    Vector2i position;
    QPixmap picture;
    float relativeScale;
    PivotLocation pivotLocation;

public:
    static int globalScale;

    virtual Vector2i getPosition();
    virtual void setPosition(int x, int y);
    virtual QPixmap getPicture();
    virtual void setPicture(QPixmap pic);
    virtual void setPicture(string relativePath);
    virtual float getRelativeScale();
    virtual void setRelativeScale(float relativeScaleValue);
    virtual PivotLocation getPivotLocation();
    virtual void setPivotLocation(PivotLocation pivot);

};

#endif // GAMEOBJECT_H
