#include "game.h"
#include <iostream>
#include <cctype>
#include <memory>
#include <cstdlib>  
#include <ctime>    
#include "dungeon.h"
#include "player.h"

Game::Game() {
    running = true;
    std::srand(std::time(nullptr));
}

void Game::start() {
    mainMenu();
}

void Game::mainMenu() {
    int choice = 0;

    while (running) {
        std::cout << "\n=== MAIN MENU ===\n";
        std::cout << "1. Start Adventure\n";
        std::cout << "2. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string playerName;
            std::cout << "Enter your name: ";
            std::cin >> playerName;
            Player player(playerName);

            std::cout << "\nYou step into the darkness of the dungeon...\n";

            exploreDungeon(player);
        }
        else if (choice == 2) {
            quit();
        }
        else {
            std::cout << "Invalid option!\n";
        }
    }
}

void Game::exploreDungeon(Player& player) {
    Dungeon dungeon(10, 10);
    char input;
    bool exploring = true;

    std::cout << "\nYou enter the dungeon...\n";

    while (exploring) {
        dungeon.display();

        std::cout << "\nCoins: " << player.getCoins() 
                  << " | HP: " << player.getHP() << "\n";

        std::cout << "Move (WASD) or Q to quit dungeon: ";
        std::cin >> input;
        input = std::tolower(input);

        if (input == 'q') {
            std::cout << "You leave the dungeon.\n";
            exploring = false;
            continue;
        }

        dungeon.movePlayer(input);

        
        if ((std::rand() % 100) < 30) { 
            int amount = 1 + std::rand() % 5;
            player.addCoins(amount);
        }

       
        if (dungeon.isAtExit()) {
            std::cout << "\nYou see the light of the exit!\n";
            exploring = false;
        }
    }
}

void Game::quit() {
    std::cout << "Exiting game...\n";
    running = false;
}

