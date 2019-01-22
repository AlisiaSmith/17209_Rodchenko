#pragma once

#include <iostream>

#include "Player.h"
#include "Factory.h"

class StrategyOf21Score : public Player
{
  public:
  bool ShoudTakeNext() { return GetScore() < 21; }
  std::string WhoAmI() const { return "StrategyOf21Score"; }
};

namespace {


    Player * createStrategyOf21Score() {
        return new StrategyOf21Score;
    }

    Player* (*fcnPtr21)() = createStrategyOf21Score;

    bool ok21 = Factory<std::string, decltype(createStrategyOf21Score)>::getInstance()
            ->registerPlayer("21score", *fcnPtr21);

}