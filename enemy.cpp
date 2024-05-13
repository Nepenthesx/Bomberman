#include "enemy.h"

#include <stdlib.h>
#include "gamemanager.h"
#include "walltile.h"
#include "rocktile.h"
#include "player.h"

Enemy::Enemy(QVector<int> position, QVector<int> size, int speed, int durability)
    : Character(position, size, speed, durability)
{
    relativeClosePositions.insert(QVector<int>({1, 0}));
    relativeClosePositions.insert(QVector<int>({0, 1}));
    relativeClosePositions.insert(QVector<int>({-1, 0}));
    relativeClosePositions.insert(QVector<int>({0, -1}));

    srand(0);
}

void Enemy::update()
{
    if (getDurability() <= 0)
        onDurabilityLoss();

    QSet objectsInContact(GameManager::getObjectsInContactArea(getPosition(), relativeClosePositions, getSize()));
    QVector<QVector<int>> positionsToMove;

    for (GameObject* object : objectsInContact)
    {
        if (dynamic_cast<WallTile*>(object) || dynamic_cast<RockTile*>(object))
            continue;

        //jeśli sąsiaduje z graczej to rusza na niego!
        if (dynamic_cast<Player*>(object))
        {
            positionsToMove.clear();
            positionsToMove.push_back(object->getPosition());
            break;
        }

        positionsToMove.push_back(object->getPosition());
    }

    int num = rand() % positionsToMove.count();
    move(positionsToMove[num]);

}

void Enemy::move(QVector<int> nextPosition)
{
    //kolizja nie mogła wystąpić - zrób ruch
    setPosition(nextPosition);

    //zadaj graczowi obrażenia
    QList<GameObject*> objectsInContact(GameManager::getObjectsInContact(getPosition(), getSize()));
    for (GameObject* object : objectsInContact)
    {
        if(Player* player = dynamic_cast<Player*>(object))
        {
            qDebug() << "Player harmed!";
            player->takeDamage(1);
        }
    }
}

void Enemy::onDurabilityLoss()
{
    desactive();
}
