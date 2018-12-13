#pragma once

#define SizeOfDeck 52

#include <ctime>

#include "Card.h"

class Deck
{
private:

Card *list;
size_t size;
int num; // карт вышло

public:

Deck ();
~Deck();

void imply();
void shuffle();
bool IsEmpty();

Card& DrawACard();



};
