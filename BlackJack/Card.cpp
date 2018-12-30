#include "Card.h"

  Card::Card() : cost(10), used (false) {}
  Card::Card(int cost) : cost(cost), used(false) {}
  Card::~Card() {}

  void Card::swap(Card& a)
  {
    Card tmp;
    tmp = a;
    a = *this;
    *this = tmp;
  }

void Card::imply(int count) { cost = count; }

Card& Card::operator=(const Card& a) { cost = a.cost; }

int Card::GetCost() const  { return cost; }

void Card::UseOn() { used = true; }
void Card::UseOff() { used = false; }
bool Card::IsUsed() { return used; }


bool Card::operator==(const Card& a) {  return cost == a.cost;  }
