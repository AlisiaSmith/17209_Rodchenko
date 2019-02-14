#pragma once

#include <iostream>

#include "Player.h"
#include "Factory.h"

class StrategyOf5Cards : public Player
{
  public:
  bool ShoudTakeNext() { return (count < 5) && (GetScore() < 21); }
  std::string WhoAmI() const { return "StrategyOf5Cards"; }
};

namespace {

    Player * createStrategyMax5() {
        return new StrategyOf5Cards;
    }

    Player* (*fcnPtr5)() = createStrategyMax5;

    bool ok5 = Factory<std::string,  Player* (*)()>::getInstance()
            ->registerPlayer("max5", fcnPtr5);

}
