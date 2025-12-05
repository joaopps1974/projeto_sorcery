#ifndef SPY_H
#define SPY_H

#include "../player.h"
#include <string>

class Spy : public Player {
public:
    Spy(const std::string& name);
};

#endif

