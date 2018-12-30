#pragma once


#include "Player.h"

class StrategyOf19Score :: public Player
{
  #define MAX_SCORE 19
public:
  bool ShoudTakeNext();
}


bool StrategyOf17Score::ShoudTakeNext() { return GetScore() < MAX_SCORE; }
