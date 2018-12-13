#pragma once

//#include <ctime>

class Game
{
private:

Deck *d;
size_t count;
int used;

Croupier croup;
int num_of_players;
Player *pl;

public:
Game();
~Game();

Card& DrawACard() const;

void finish();

}
