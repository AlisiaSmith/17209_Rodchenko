#pragma once

#define MAX_COUNT_CARD 5


#include "Player.h"

class StrategyOf17Score :: public Player
{
  bool ShoudTakeNext();
}


bool StrategyOf17Score::ShoudTakeNext() { return count < MAX_COUNT_CARD; }
