#pragma once




#include "Player.h"

class StrategyOf17Score : public Player
{
  public:
  bool ShoudTakeNext() { return GetScore() < 17; }
  std::string WhoAmI() const { return "StrategyOf17Score"; }
};
