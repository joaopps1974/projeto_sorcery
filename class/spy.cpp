#include "../class/spy.h"
#include <iostream>

Spy::Spy(const std::string& name)
    : Player(name, 28, 11, 22, 9) // hp, dano, va, acerto
{
    std::cout << name << " The Spy leaves the cell\n";
}
