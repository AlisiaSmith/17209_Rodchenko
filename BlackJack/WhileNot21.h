#pragma once

#define MAX_SCORE 21

#include "Player.h"

class StrategyOf21Score :: public Player
{
  bool ShoudTakeNext();
}


bool StrategyOf17Score::ShoudTakeNext() { return GetScore() < MAX_SCORE; }
