#pragma once

#include <iostream>

enum suits{ hearts, diamonds, clubs, spades };

class Card {
private:
  suits suit;
  int cost;
  bool leave;
  bool OnHands;
public:
  Card();
  Card(suits suit, int cost);
  ~Card();

  Card& operator=(const Card& a);

  void swap(Card& a);

  int GetCost() const;
  suits GetSuit() const;

  void imply(suits s, int count);

  void UseOn();
  void UseOff();
  bool IsUsed() const;
  void HoldOff();
  bool IsHold() const;

  bool operator==(const Card& a);
};
