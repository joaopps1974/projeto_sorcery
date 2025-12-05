#include "../class/weaponmaster.h"
#include <iostream>

WeaponMaster::WeaponMaster(const std::string& name)
    : Player(name, 32, 11, 20, 11) // hp, dano, va, acerto 
{
    std::cout << name << " The Weapon Master leaves the cell\n";
}
