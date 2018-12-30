#pragma once

#define MAX_SCORE 19


#include "Player.h"

class StrategyOf19Score :: public Player
{
  bool ShoudTakeNext();
}


bool StrategyOf17Score::ShoudTakeNext() { return GetScore() < MAX_SCORE; }
