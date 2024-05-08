#include "graphicobject.h"


GraphicObject::GraphicObject(GameObject* gameObject, std::string graphicRelativePath, QWidget* parent, int drawingPriority)
    : QWidget (parent)
{
    this->gameObject = gameObject;
    setPicture(graphicRelativePath);
    setDrawingPriority(drawingPriority);
}

QPixmap GraphicObject::getPicture()
{
    return picture;
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

int GraphicObject::getDrawingPriority()
{
    return drawingPriority;
}

void GraphicObject::setDrawingPriority(int drawingPriority)
{
    if (drawingPriority >= 0)
        this->drawingPriority = drawingPriority;
    else
        drawingPriority = 0;
}

GameObject* GraphicObject::getGameObject()
{
    return gameObject;
}

bool comparePriority(GraphicObject* a, GraphicObject* b)
{
    return (a->getDrawingPriority() < b->getDrawingPriority());
}

void GraphicObject::sortByPriority(QList<GraphicObject*> objectsList)
{
    std::sort(objectsList.begin(), objectsList.end(), comparePriority);
    for(QWidget* object : objectsList)
    {
        object->raise();
    }
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
