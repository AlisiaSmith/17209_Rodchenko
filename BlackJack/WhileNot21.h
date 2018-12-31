#pragma once



#include "Player.h"

class StrategyOf21Score : public Player
{
  public:
  bool ShoudTakeNext() { return GetScore() < 21; }
  std::string WhoAmI() const { return "StrategyOf21Score"; }
};
