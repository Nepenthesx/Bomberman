#include "mainwindow.h"
#include "board.h"

#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();

    Board board(mainWindow.centralWidget(), 20, 10, 32);
    board.show();

    return app.exec();
}
