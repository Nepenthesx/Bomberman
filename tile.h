#ifndef TILE_H
#define TILE_H

#include "gameobject.h"

#include <QImage>
#include <QPixmap>

#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

class Tile : public GameObject
{
private:
    Tile* leftTile = nullptr;
    Tile* rightTile = nullptr;
    Tile* upTile = nullptr;
    Tile* downTile = nullptr;
    bool isDestructible;
    bool isPermeable;

public:
    Tile();
    Tile(string relativePath, bool destructibility, bool permeability, float relativeScale = 1);
    Tile(Tile* left, Tile* right, Tile* up, Tile* down, bool destructibility, bool permeability);

    Tile* getLeftTile();
    void setLeftTile(Tile* tile);
    Tile* getRightTile();
    void setRightTile(Tile* tile);
    Tile* getUpTile();
    void setUpTile(Tile* tile);
    Tile* getDownTile();
    void setDownTile(Tile* tile);
    bool getDestructibility();
    void setDestructibility(bool destructibility);
    bool getPermeability();
    void setPermeability(bool permeability);

    int number;

    //Vector2i getPosition();
    //void setPosition(int x, int y);
    //QPixmap getPicture();
    //void setPicture(QPixmap pic);
    //void setPicture(string relativePath);
};

#endif // TILE_H
