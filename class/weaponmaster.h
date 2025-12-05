#ifndef WEAPONMASTER_H
#define WEAPONMASTER_H

#include "../player.h"
#include <string>

class WeaponMaster : public Player {
public:
    WeaponMaster(const std::string& name);
};

#endif
