#include "Card.h"

  Card::Card() : cost(10), leave (false), OnHands(false) {}
  Card::Card(suits suit, int cost) : suit(suit), cost(cost), leave(false), OnHands(false) {}
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
  leave = a.IsUsed();
  return *this;
}

int Card::GetCost() const  { return cost; }
suits Card::GetSuit() const { return suit; }

void Card::UseOn() { leave = true; OnHands = true;}
void Card::UseOff() { leave = false; }
bool Card::IsUsed() const { return leave; }
void Card::HoldOff() { OnHands = false; }

bool Card::operator==(const Card& a) {  return (suit == a.suit) && (cost == a.cost);  }
