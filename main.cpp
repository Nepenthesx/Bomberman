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


    // 50/3 = 60 fps
    GameManager gameManager(64, mainWindow.centralWidget(), 200);
    gameManager.startLevel();

    return app.exec();
}
