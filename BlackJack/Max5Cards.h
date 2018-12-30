#pragma once


#include "Player.h"

class StrategyOf5Cards :: public Player
{
  #define MAX_COUNT_CARD 5
public:
  bool ShoudTakeNext();
}


bool StrategyOf5Cards::ShoudTakeNext() { return (count < MAX_COUNT_CARD) && (GetScore() < 21); }
