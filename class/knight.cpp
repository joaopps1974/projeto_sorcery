#include "../class/knight.h"
#include <iostream>

Knight::Knight(const std::string& name)
    : Player(name, 32, 9, 23, 9) // hp, dano, va, acerto
{
    std::cout << name << " The Knight leaves the cell\n";
}
