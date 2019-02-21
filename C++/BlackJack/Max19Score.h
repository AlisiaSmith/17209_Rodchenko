#pragma once

#include <iostream>

#include "Player.h"
#include "Factory.h"

class StrategyOf19Score : public Player
{
public:
  bool ShoudTakeNext() { return GetScore() < 19; }
  std::string WhoAmI() const { return "StrategyOf19Score"; }
};

namespace {

    Player * createStrategyOf19Score() {
        return new StrategyOf19Score;
    }

    Player* (*fcnPtr19)() = createStrategyOf19Score;

	bool ok19 = Factory<std::string,  Player* (*)()>::getInstance()
			->registerPlayer("st2", fcnPtr19);

}
