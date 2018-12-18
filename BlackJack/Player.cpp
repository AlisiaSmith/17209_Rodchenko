 
#include "Player.h"

Player::Player() : score(0), count(0) {  list = new Card [MAX_CARDS];  }

Player::~Player() {  delete[] list;  }

bool Player::DoesHaveThisCard(Card& a) const
{
    for (int i = 0; i < count; i++)     if(list[i] == a) return true;
    return false;
}

int Player::GetScore() const {  return score;  }

void Player::PutCard(Card& a)
{
    list[count] = a;
    score += a.GetCost();
    count++;
}

void Player::ClearList() {  score = 0; count = 0;   }

