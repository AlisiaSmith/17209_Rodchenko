
#include "Game.h"


Game::Game(){}
Game::~Game(){}

Card& Game::DrawACard()
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
