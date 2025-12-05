#ifndef COMBAT_H
#define COMBAT_H

#pragma once
#include "player.h"
#include "enemy.h"

class Combat {
public:
    static void start(Player& player, Enemy& enemy);
};

#endif
