
#include "Game.h"


Game::Game(Player* ls, int num_of_pl, int num_of_dec) : num_of_decks(num_of_dec), num_of_players(num_of_pl), pl(ls)
{
  count = num_of_decks * SizeOfDeck;
  used = 0u;
  hold = 0u;
  critical  = count / 3;

  d = new Deck [num_of_decks];
}
Game::~Game(){}

Card Game::DrawACard()
{
  srand( time( 0 ));
  int i = rand() % num_of_decks;
  while (d[i].IsEmpty()) i = (i++) % (num_of_decks + 1);
  used++;
  hold++;
  return d[i].DrawACard();
}

void Game::BackCards()
{
    for (int i = 0; i < num_of_decks; i++)
        d[i].BackCards();
    used = hold;
}

void Game::process()
{
  for(int i = 0; i < num_of_players; i++)
    while(pl[i].ShoudTakeNext())
    {
      Card a = DrawACard();
      pl[i].PutCard(a);
      if(IsCritical()) BackCards();
      if (pl[i].GetScore() > 21)
      {
          hold = hold - pl[i].GetCount();
          pl[i].lose();
          break;
      }
      if (pl[i].GetScore() == 21) pl[i].won();
    }
}


bool Game::IsCritical() const { return critical <= (count - used); }
