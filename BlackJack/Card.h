#pragma once

#include <iostream>
#include <string>



class Card {
private:
  int cost;
  bool used;
public:
  Card();
  Card(int cost);
  ~Card();

  Card& operator=(const Card& a);

  void swap(Card& a);

  int GetCost() const;

  void imply(int count);

  void UseOn();
  void UseOff();
  bool IsUsed();

  bool operator==(const Card& a);
};
