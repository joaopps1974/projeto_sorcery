#include "player.h"
#include <iostream>

void Player::takeDamage(int dmg) {
    int damageTaken = dmg ;
    if (damageTaken < 0) damageTaken = 0;
    hp -= damageTaken;
    if (hp < 0) hp = 0;
    std::cout << name << " takes " << damageTaken << " damage! (HP: " << hp << ")\n";
}

void Player::addCoins(int amount) {
    if (amount > 0) {
       coins += amount;
       std::cout << name << "has found" << amount << " coins. (Total of " << coins << ")\n";
    }
}
