#include "player.h"
#include "gamemanager.h"


Player::Player(QVector<int> position, QVector<int> size, int durability, int speed, int maxBombCount, int bombPower, Bomber::BombType bombType)
    : Bomber(position, size, durability, speed, maxBombCount, bombPower, bombType)
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
    GameManager::removeObject(this);
}

void Player::pickItem()
{
    QList<GameObject*> objectsInContact(GameManager::getObjectsInContact(getPosition(), size));

    for (GameObject* object : objectsInContact)
    {
        if (dynamic_cast<BombUpgrade*>(object))
        {
            qDebug() << "Picked Bomb Upgrade!";

            if (bombType == Player::Cross)
                setBombType(Player::Square);
            else if(bombType == Player::Square)
                setBombType(Player::Cross);

            GameManager::removeObject(object);
        }
        else if (dynamic_cast<PowerUpgrade*>(object))
        {
            qDebug() << "Picked Power Upgrade!";

            setBombPower(bombPower + 1);

            GameManager::removeObject(object);
        }
    }
}


