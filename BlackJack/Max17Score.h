#pragma once




#include "Player.h"

class StrategyOf17Score :: public Player
{
  #define MAX_SCORE 17
public:
  bool ShoudTakeNext();
}


bool StrategyOf17Score::ShoudTakeNext() { return GetScore() < MAX_SCORE; }
