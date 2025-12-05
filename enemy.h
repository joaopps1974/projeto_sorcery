#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy {
private:
    std::string name;
    int hp;
    int maxHp;
    int attack;
    int armorClass;
    int attackBonus;
    int coinDrop;

public:
    Enemy(const std::string& n, int h, int a, int ac, int atkBonus = 0, int coins = 0);

    int getAttack() const;
    int getHP() const;
    int getArmorClass() const;
    int getAttackBonus() const;
    int getCoinDrop() const { return coinDrop; };
    std::string getName() const;

    bool isAlive() const;

    void takeDamage(int dmg);

    void setAttackBonus(int bonus);
};

#endif 
