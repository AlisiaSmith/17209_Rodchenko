
#include "Player.h"

Player::Player() : score(0), count(0) {  list = new Card [MAX_CARDS];  }

virtual Player::~Player() {  delete[] list;  }

int Player::GetScore() const {  return score;  }

void Player::PutCard(Card& a)
{
    list[count] = a;
    score += a.GetCost();
    count++;
}
