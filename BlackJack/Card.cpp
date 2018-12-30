#include "Card.h"

  Card::Card() : cost(10), used (false) {}
  Card::Card(suits suit, int cost) : suit(suit), cost(cost), used(false) {}
  Card::~Card() {}

  void Card::swap(Card& a)
  {
    Card tmp;
    tmp = a;
    a = *this;
    *this = tmp;
  }

  void Card::imply(suits s, int count)
  {
    suit = s;
    cost = count;
  }

Card& Card::operator=(const Card& a)
{
  if (&a == this) return *this;
  suit = a.GetSuit();
  cost = a.GetCost();
  lrave = a.IsUsed();
  return *this;
}

int Card::GetCost() const  { return cost; }
suits GetSuit() const { return suit; }

void Card::UseOn() { leave = true; }
void Card::UseOff() { leave = false; }
bool Card::IsUsed() { return leave; }


bool Card::operator==(const Card& a) {  return (suit == a.suit) && (cost == a.cost);  }
