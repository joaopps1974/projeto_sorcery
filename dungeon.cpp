#include "dungeon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Dungeon::Dungeon(int w, int h) : width(w), height(h) {
    map = std::vector<std::vector<char>>(height, std::vector<char>(width, '.'));

    // Add walls
    for (int i = 0; i < width; ++i) {
        map[0][i] = '#';
        map[height - 1][i] = '#';
    }
    for (int i = 0; i < height; ++i) {
        map[i][0] = '#';
        map[i][width - 1] = '#';
    }

    // Place player at start
    playerX = 1;
    playerY = 1;
    map[playerY][playerX] = 'P';

    // Place exit
    exitX = width - 2;
    exitY = height - 2;
    map[exitY][exitX] = 'X';


    std::srand(std::time(nullptr));
}

void Dungeon::display() const {
    for (const auto& row : map) {
        for (char tile : row) {
            std::cout << tile << ' ';
        }
        std::cout << '\n';
    }
}

void Dungeon::movePlayer(char direction) {
    int newX = playerX;
    int newY = playerY;

    switch (direction) {
        case 'w': newY--; break;
        case 's': newY++; break;
        case 'a': newX--; break;
        case 'd': newX++; break;
        default:
            std::cout << "Invalid input! Use WASD.\n";
            return;
    }

    if (map[newY][newX] == '#') {
        std::cout << "A wall blocks your path.\n";
        return;
    }

    map[playerY][playerX] = '.';
    playerX = newX;
    playerY = newY;
    map[playerY][playerX] = 'P';
}

bool Dungeon::isAtExit() const {
    return playerX == exitX && playerY == exitY; // suposto de terminar programa caso chegue no x
}


bool Dungeon::encounterEnemy() const {
    return (std::rand() % 100) < 40; // 40% de chance de encontro
}
