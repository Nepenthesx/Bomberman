#include "player.h"
#include "gamemanager.h"


Player::Player(QVector<int> position, QVector<int> size, int durability, int speed) : Character(position, size, durability, speed)
{

}

void Player::update()
{
    //QList<GameObject*> objectsInRange(GameManager::getObjectsInRange(this, speed).count());

    if (GetAsyncKeyState(VK_LEFT))
    {
        qDebug() << "Left";
        move(QVector<int>({position[0] - speed, position[1]}));
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        qDebug() << "Right";
        move(QVector<int>({position[0] + speed, position[1]}));
    }
    if (GetAsyncKeyState(VK_UP))
    {
        qDebug() << "Up";
        move(QVector<int>({position[0], position[1] - speed}));
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        qDebug() << "Down";
        move(QVector<int>({position[0], position[1] + speed}));
    }
}

void Player::move(QVector<int> nextPosition)
{
    QList<GameObject*> objectsInContact(GameManager::getObjectsInContact(nextPosition, size));
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
    delete this;
}
