#pragma once

#include <iostream>
#include <ctime>

#include "Deck.h"
#include "Card.h"
#include "Player.h"
//#include "Croupier.h"

class Game
{
private:

Deck *d;
int num_of_decks;
size_t count;
int used;

int critical; //высчитывается при задании num_of_decks

//Croupier croup;
int num_of_players;
//Player *pl;

public:
Game();
~Game();

Card DrawACard() const;

void BackCards();

void finish();

};
