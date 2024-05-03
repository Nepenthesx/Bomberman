#include "mainwindow.h"
#include "gamemanager.h"

#include <QApplication>
#include <QDebug>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();

    GameManager gameManager(32, 100, GameManager::First, mainWindow.centralWidget());
    gameManager.startLevel();

    // 50/3 = 60 fps
    //GraphicsManager graphicsManager(mainWindow.centralWidget(), Vector2i(20, 10), 32, 12.5);
    //graphicsManager.show();

    return app.exec();
}
