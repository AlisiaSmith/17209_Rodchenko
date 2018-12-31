
#include "Game.h"


Game::Game(std::vector<Player*> ls, int num_of_dec) : num_of_decks(num_of_dec), pl(ls)
{
  count = num_of_decks * SizeOfDeck;
  used = 0u;
  hold = 0u;
  critical  = count / 3;

  d = new Deck [num_of_decks];

  process();
}
Game::~Game(){ delete[] d; }

Card Game::DrawACard()
{
  //srand( time( 0 ));
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

    for (int i = 0; i < num_of_decks; i++)
        d[i].shuffle();
}

void Game::process()
{
  for(int i = 0; i < pl.size(); i++)
    while(pl[i]->ShoudTakeNext())
    {
      Card a = DrawACard();
      pl[i]->PutCard(a);
      if(IsCritical()) BackCards();
      if (pl[i]->GetScore() > 21)
      {
          hold = hold - pl[i]->GetCount();
          pl[i]->lose();
          break;
      }
      if (pl[i]->GetScore() == 21) pl[i]->won();
    }
}

void Game::finish()
{
    std::cout << "Scores:" << std::endl << std::endl;

    for(int i = 0; i < pl.size(); i++)
        std::cout << pl[i]->WhoAmI()  << ": " << pl[i]->GetScore() << std::endl;

    int Max = 0, i = 0, who = 0;

    for(i; i < pl.size(); i++)
        if(pl[i]->GetScore() > Max)
        {
            if (pl[i]->GetScore() > 21) continue;
            Max = pl[i]->GetScore();
            who = i;
        }

    std::cout << std::endl;
    std::cout << pl[who]->WhoAmI()  << " - winer!!!" << std::endl;

}




bool Game::IsCritical() const { return critical <= (count - used); }
