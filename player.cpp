#include "player.h"

#include "gamemanager.h"
#include "walltile.h"
#include "rocktile.h"
#include "bombtypeupgrade.h"
#include "bombpowerupgrade.h"
#include "bombcountupgrade.h"


Player::Player(QVector<int> position, QVector<int> size, int speed, int durability, int maxBombCount, int bombPower, Bomber::BombType bombType)
    : Bomber(position, size, speed, durability, maxBombCount, bombPower, bombType)
{

}

void Player::update()
{
    //ŻYCIE
    if (getDurability() <= 0)
        onDurabilityLoss();

    //RUCH
    if (GetAsyncKeyState(VK_LEFT))
    {
        qDebug() << "Left";
        move(QVector<int>({getPosition()[0] - getSpeed(), getPosition()[1]}));
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        qDebug() << "Right";
        move(QVector<int>({getPosition()[0] + getSpeed(), getPosition()[1]}));
    }
    if (GetAsyncKeyState(VK_UP))
    {
        qDebug() << "Up";
        move(QVector<int>({getPosition()[0], getPosition()[1] - getSpeed()}));
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        qDebug() << "Down";
        move(QVector<int>({getPosition()[0], getPosition()[1] + getSpeed()}));
    }
    //BOMBA
    if(GetAsyncKeyState(VK_SPACE))
    {
        qDebug() << "Set Bomb";
        placeBomb();
    }

    //PRZEDMIOT
    pickItem();
}

void Player::move(QVector<int> nextPosition)
{
    QList<GameObject*> objectsInContact(GameManager::getObjectsInContact(nextPosition, getSize()));
    for (GameObject* object : objectsInContact)
    {
        if(dynamic_cast<WallTile*>(object) || dynamic_cast<RockTile*>(object))
        {
            qDebug() << "Collision!";
            return;
        }
    }

    //kolizja nie wystąpiła - zrób ruch
    setPosition(nextPosition);
}

void Player::onDurabilityLoss()
{
    qDebug() << "Game Over!";
    GameManager::endLevel();
    //desactive();
}

void Player::pickItem()
{
    QList<GameObject*> objectsInContact(GameManager::getObjectsInContact(getPosition(), getSize()));

    for (GameObject* object : objectsInContact)
    {
        if (dynamic_cast<BombTypeUpgrade*>(object))
        {
            qDebug() << "Picked BombType Upgrade!";

            if (getBombType() == Player::Cross)
                setBombType(Player::Square);
            else if (getBombType() == Player::Square)
                setBombType(Player::Cross);

            object->desactive();
        }
        else if (dynamic_cast<BombPowerUpgrade*>(object))
        {
            qDebug() << "Picked BombPower Upgrade!";

            setBombPower(getBombPower() + 1);

            object->desactive();
        }
        else if (dynamic_cast<BombCountUpgrade*>(object))
        {
            qDebug() << "Picked BombCount Upgrade!";

            setMaxBombCount(getMaxBombCount() + 1);

            object->desactive();
        }

    }
}


