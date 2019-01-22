#pragma once

#include <iostream>

#include "Player.h"
#include "Factory.h"


class StrategyOf17Score : public Player
{
  public:
  bool ShoudTakeNext() { return GetScore() < 17; }
  std::string WhoAmI() const { return "StrategyOf17Score"; }
};

namespace {

    Player * createStrategyOf17Score() {
        return new StrategyOf17Score;
    }

    Player* (*fcnPtr17)() = createStrategyOf17Score;

    bool ok17 = Factory<std::string, decltype(createStrategyOf17Score)>::getInstance()
		->registerPlayer("17score", *fcnPtr17);

}
