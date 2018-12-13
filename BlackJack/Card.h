#pragma once

#include <iostream>
#include <string>


enum suits{ hearts, diamonds, clubs, spades };

class Card {
private:
  suits suit;
  int cost;
public:
  Card();
  Card(suits suit, int cost);
  ~Card();

  Card& operator=(const Card& a);

  void swap(Card& a);

  void imply(suits s, int count);

  bool operator==(const Card& a);
};
