#include "bestiary.h"
#include "enemy.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Enemy Bestiary::createEnemy(const std::string& name) const {
    if (name == "Zombie Guard") {
        return Enemy("Zombie Guard", 30, 5, 13, 7, 10);
    } else if (name == "Shieldbearer") {
        return Enemy("Shieldbearer", 20, 4, 19, 7, 15);
    } else if (name == "Gunslinger") {
        return Enemy("Gunslinger", 15, 9, 16, 9, 15);
    } else if (name == "Grenadier") {
        return Enemy("Grenadier", 30, 11, 18, 11, 30);
    } else {
        std::cout << "Unknown enemy: " << name << ". Summoning a placeholder enemy.\n";
        return Enemy("Nameless Horror", 10, 4, 1);
    }
}

Enemy Bestiary::createRandomEnemy() const {
    int roll = rand() % 4; // número entre 0 e 3
    switch (roll) {
        case 0: return createEnemy("Zombie Guard");
        case 1: return createEnemy("Shieldbearer");
        case 2: return createEnemy("Gunslinger");
        case 3: return createEnemy("Grenadier");
        default: return createEnemy("Zombie Guard"); // fallback
    }
}


std::vector<std::string> Bestiary::listEnemies() const {
    return {"Zombie Guard", "Shieldbearer", "Gunslinger", "Grenadier"};
}
