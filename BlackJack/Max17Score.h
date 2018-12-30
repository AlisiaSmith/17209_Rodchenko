#pragma once

#define MAX_SCORE 17


#include "Player.h"

class StrategyOf17Score :: public Player
{
  bool ShoudTakeNext();
}


bool StrategyOf17Score::ShoudTakeNext() { return GetScore() < MAX_SCORE; }
