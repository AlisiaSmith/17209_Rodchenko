#pragma once



#include "Player.h"

class StrategyOf21Score :: public Player
{
  #define MAX_SCORE 21
public:
  bool ShoudTakeNext();
}


bool StrategyOf17Score::ShoudTakeNext() { return GetScore() < MAX_SCORE; }
