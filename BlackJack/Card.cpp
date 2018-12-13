#include "Card.h"

  Card::Card(suits suit, int cost) : suit(suit), cost(cost) {}

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
  suit = a.suit;
  cost = a.cost;
}


bool operator==(const Card& a) {  return (suit == a.suit) && (cost == a.cost);  }
