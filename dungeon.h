#ifndef DUNGEON_H
#define DUNGEON_H

#include <vector>
#include <string>

class Dungeon {
private:
    int width;
    int height;
    std::vector<std::vector<char>> map;
    int playerX;
    int playerY;
    int exitX, exitY;

public:
    Dungeon(int w, int h);

    void display() const;
    void movePlayer(char direction);
    bool isAtExit() const;
    bool encounterEnemy() const;
};

#endif
