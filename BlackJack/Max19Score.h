#pragma once


#include "Player.h"

class StrategyOf19Score : public Player
{
public:
  bool ShoudTakeNext() { return GetScore() < 19; }
  std::string WhoAmI() const { return "StrategyOf19Score"; }
};

