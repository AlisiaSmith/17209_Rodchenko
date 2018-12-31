#pragma once


#include "Player.h"

class StrategyOf5Cards : public Player
{
  public:
  bool ShoudTakeNext() { return (count < 5) && (GetScore() < 21); }
  std::string WhoAmI() const { return "StrategyOf5Cards"; }
};

