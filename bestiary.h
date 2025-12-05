#ifndef BESTIARY_H
#define BESTIARY_H

#include "enemy.h"
#include <vector>
#include <string>

class Bestiary {
public:
    Bestiary() = default;

    Enemy createRandomEnemy() const;
    Enemy createEnemy(const std::string& name) const;
    std::vector<std::string> listEnemies() const;
};

#endif
