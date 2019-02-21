
#include "Player.h"

Player::Player() : score(0), count(0) {  list = new Card [MAX_CARDS];  }

Player::~Player() {  delete[] list;  }

int Player::GetScore() const {  return score;  }
int Player::GetCount() const {  return count;  }

void Player::PutCard(Card& a)
{
    list[count] = a;
    score += a.GetCost();
    count++;
}

void Player::lose()
{
     ClearList();
}

void Player::won()
{
    wins++;
}

void Player::ClearList()
{
    for(int i = 0; i < count; i++)
        list[i].HoldOff();
    count = 0;
}

bool Player::ShoudTakeNext() { return true; }
std::string Player::WhoAmI() const { return "Player"; }