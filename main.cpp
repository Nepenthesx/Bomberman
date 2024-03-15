#include "mainwindow.h"
#include "graphicsmanager.h"

#include <iostream>
#include <QApplication>
#include <QDebug>

#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();

    // 50/3 = 60 fps
    GraphicsManager graphicsManager(mainWindow.centralWidget(), Vector2i(20, 10), 32, 12.5);
    graphicsManager.show();

    return app.exec();
}
