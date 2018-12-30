
#include "Game.h"


Game::Game(Player* ls, int num_of_pl, int num_of_dec) : num_of_decks(num_of_dec), num_of_players(num_of_pl), pl(ls)
{
  count = num_of_decks * SizeOfDeck;
  used = 0u;
  critical  = count / 3;

  d = new Deck [num_of_decks];
}
Game::~Game(){}

Card& Game::DrawACard() const ()
{
  srand( time( 0 ));
  int i = rand() % num_of_decks;
  while (d[i].IsEmpty()) i = (i++) % num_of_decks;
  used ++;
  return d[i].DrawACard();
}

void Game::BackCards()
{

}

void Game::process()
{
  for(int i = 0; i < num_of_players; i++)
    while(pl[i].ShoudTakeNext())
    {
      pl[i].PutCard();
      if(IsCritical()) BackCards();
      if (pl[i].GetScore() > 21)
      {
        pl[i].lose();
        break;
      }
      if (pl[i].GetScore() == 21) pl[i].won();
    }
}


bool IsCritical() const { return critical <= (count - used); }
