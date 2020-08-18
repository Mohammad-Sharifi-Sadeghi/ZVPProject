#include <QApplication>
#include "Game.h"
#include <stdlib.h>
#include <time.h>

Game* game;

int main(int argc, char *argv[]){
    srand( time( 0 ) );
    QApplication a(argc, argv);
    game = new Game();
    game->show();
    game->showMainMenu();

    return a.exec();
}
