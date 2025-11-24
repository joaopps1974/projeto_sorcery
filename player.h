#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Player {
private:
    std::string name;
    int hp;
    int maxHp;
    int atk;
    int armorClass;
    int attackBonus;
    int coins;   

public:
    Player(std::string n, int h, int a, int ac, int atkBonus)
        : name(n), hp(h), maxHp(h), atk(a), armorClass(ac), attackBonus(atkBonus), coins(0) {}
    Player(const std::string& n)
        : name(n), hp(8), maxHp(8), atk(2), armorClass(13), attackBonus(4), coins(0) {}     

    int getAttack() const { return atk; }
    int getHP() const { return hp; }
    int getArmorClass() const { return armorClass; }
    int getAttackBonus() const { return attackBonus; }
    int getCoins() const { return coins; }
    std::string getName() const { return name; }    
    
    bool isAlive() const { return hp > 0; }

    void addCoins(int amount);
    
    void takeDamage(int dmg);
};

#endif
