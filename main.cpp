#include "game.h"
#include <windows.h>
#include <iostream>

int main() {
    SetConsoleOutputCP(65001);
    Game game;
    game.start();
    return 0;
}
