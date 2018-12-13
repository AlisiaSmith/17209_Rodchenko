#include <ctime>

#include "Deck.h"




Deck::Deck() : size(SizeOfDeck), num(0)
{
  list = new Card[SizeOfDeck];
  imply();
  shuffle();
}
Deck::~Deck() { delete[] list;  }

void Deck::imply()
{
  if(!list) return;
  for (int i = 0, i < 10, i++)
  {
      list[i].imply("hearts", i + 1);
      list[i + 13].imply("diamonds", i + 1);
      list[i + 26].imply("clubs", i + 1);
      list[i + 39].imply("spades", i + 1);
  }

  for (int i = 0, i < 3, i++)
  {
      list[i + 10].imply("hearts", 10);
      list[i + 13 + 10].imply("diamonds", 10);
      list[i + 26 + 10].imply("clubs", 10);
      list[i + 39 + 10].imply("spades", 10);
  }
}

void Deck::shuffle()
{
  int count = 1 + srand( time( 0 )) % 100; // перетосовать от 1 до 100 раз

  for(int i = 0, i < count, i++)
  {
  int val_1 = srand( time( 0 )) % size;
  int val_2 = srand( time( 0 )) % size;

  list[val_1].swap(list[val_2]);
  }
}

bool Deck::IsEmpty() {  return !(num < size)}

Card& DrawACard() const
{
  if(IsEmpty) return NULL;
  num++;
  return list[num - 1];
}
