#include "combat.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

void Combat::start(Player& player, Enemy& enemy) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::cout << "\nCombat started between " << player.getName()
              << " and " << enemy.getName() << "!\n";

    while (player.isAlive() && enemy.isAlive()) {
        int choice = 0;

        std::cout << "\n--- Your Turn ---\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Pass Turn\n";
        std::cout << "3. Flee\n";
        std::cout << "Choose an action: ";
        std::cin >> choice;

        int roll = 0;
        int totalAttack = 0;

        if (choice == 3) {
           std::cout << player.getName() << " fled from battle!\n";
           return;
        }
       
        if (choice == 1) {
           int roll = rand() % 20 + 1;
           int totalAttack = roll + player.getAttackBonus();
           std::cout << "\nYou roll a " << roll << " (+" << player.getAttackBonus()
                     << ") = " << totalAttack << " vs Enemy AC "
                     << enemy.getArmorClass() << "\n";
        
           if (totalAttack >= enemy.getArmorClass()) {
              std::cout << "You hit " << enemy.getName()
                        << " for " << player.getAttack() << " damage!\n";
              enemy.takeDamage(player.getAttack());
           } else {
               std::cout << "You miss!\n";
           }
        
        } else if (choice == 2) {
            std::cout << player.getName() << " waits cautiously...\n";
        } else {
          std::cout << "Invalid choice! You lose your turn.\n";
        }
        
        if (!enemy.isAlive()) break;
        
        std::cout << "\n--- Enemy Turn ---\n";
        roll = rand() % 20 + 1;
        totalAttack = roll + enemy.getAttackBonus();
        std::cout << enemy.getName() << " rolls " << roll << " (+" << enemy.getAttackBonus()
                  << ") = " << totalAttack << " vs Player AC " << player.getArmorClass() << "\n";
        
        if (totalAttack >= player.getArmorClass()) {
            player.takeDamage(enemy.getAttack());
            std::cout << enemy.getName() << " hits you for " << enemy.getAttack() << " damage!\n";
        } else {
            std::cout << enemy.getName() << " misses!\n";
        }

        std::cout << "\n" << player.getName() << " HP: " << player.getHP()
                  << " | " << enemy.getName() << " HP: " << enemy.getHP() << "\n";
    }

    if (player.isAlive()) {
        std::cout << "\nYou defeated " << enemy.getName() << "!\n";
        int loot = enemy.getCoinDrop();
        player.addCoins(loot);
        std::cout << "He dropped " << loot << " coins.\n";
    }
    else {
        std::cout << "\nYou were defeated by " << enemy.getName() << "...\n";
    }
}

