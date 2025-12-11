#ifndef GAME_H
#define GAME_H

#include <string>
#include "player.h"
#include "bestiary.h"

class Game {
private:
    bool running;
    std::string title;
    Bestiary bestiary;

public:
    Game();
    void start();
    void mainMenu();
    int exploreDungeon(Player& player);
    void quit();
};

#endif
