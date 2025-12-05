#include "enemy.h"
#include <iostream>

Enemy::Enemy(const std::string& name, int hp, int atk, int ac, int atkBonus, int coins)
    : name(name), hp(hp), attack(atk), armorClass(ac), attackBonus(atkBonus), coinDrop(coins) {}

void Enemy::takeDamage(int dmg) {
    int damageTaken = dmg ;
    if (damageTaken < 0) damageTaken = 0;
    hp -= damageTaken;
    if (hp < 0) hp = 0;
    std::cout << name << " takes " << damageTaken << " damage! (HP: " << hp << ")\n";
}

int Enemy::getAttack() const { return attack; }
int Enemy::getHP() const { return hp; }
int Enemy::getArmorClass() const {return armorClass; }
int Enemy::getAttackBonus() const {return attackBonus; }

bool Enemy::isAlive() const { return hp > 0; }

std::string Enemy::getName() const { return name; }

void Enemy::setAttackBonus(int bonus) { attackBonus = bonus; }
