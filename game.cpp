#include "game.h"
#include <iostream>
#include <cctype>
#include <memory>
#include <cstdlib>  
#include <ctime>    
#include "dungeon.h"
#include "player.h"
#include "logo.h"
#include "combat.h"
#include "bestiary.h"

Game::Game() {
    running = true;
    std::srand(std::time(nullptr));
}

void Game::start() {
    Logo::print();
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

        switch (choice) {
            case 1: {
                std::string playerName;
                int classChoice;

                std::cout << "Enter your name: ";
                std::cin >> playerName;
                std::cout << "\nYou step into the darkness of the dungeon...\n";

                std::cout << "\nChoose your class:\n";
                std::cout << "1. Weapon Master (HP:32 DMG:11 AC:20 ATK:11) \n";
                std::cout << "2. Spy (HP:28 DMG:11 AC:22 ATK:9) \n";
                std::cout << "3. Knight (HP:32 DMG:9 AC:23 ATK: 9) \n";
                std::cout << "Choice: ";
                std::cin >> classChoice;

                std::unique_ptr<Player> player;

                switch (classChoice) {
                   case 1:
                       player = std::make_unique<WeaponMaster>(playerName);
                       break;
                     
                   case 2:
                        player = std::make_unique<Spy>(playerName);
                        break;

                   case 3:
                        player = std::make_unique<Knight>(playerName);
                        break;

                }

                exploreDungeon(*player);  
                break;
            }
            case 2:
                quit();
                break;
            default:
                std::cout << "Invalid choice.\n";
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

    
        if (dungeon.encounterEnemy()) {
            std::cout << "\nAn enemy appears!\n";
            Enemy foe = bestiary.createRandomEnemy(); 
            Combat::start(player, foe);

            if (!player.isAlive()) {
                std::cout << "\nYou have been defeated... The darkness consumes your soul.\n";
                running = false;
                return;
            }
        }
    }
       
    if (dungeon.isAtExit()) {
            std::cout << "\nYou see the light of the exit!\n";
            exploring = false;
        }
    }


void Game::quit() {
    std::cout << "Exiting game...\n";
    running = false;
}

