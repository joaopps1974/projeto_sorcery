#ifndef GAME_H
#define GAME_H

#include <string>
#include "player.h"

class Game {
private:
    bool running;
    std::string title;

public:
    Game();
    void start();
    void mainMenu();
    void exploreDungeon(Player& player);
    void quit();
};

#endif
