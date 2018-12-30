#pragma once

#include <iostream>
#include <ctime>

#include "Deck.h"
#include "Card.h"
#include "Player.h"


class Game
{
private:

Deck *d; // игровые коллоды
int num_of_decks; // их количесво
size_t count; // количество карт во всех коллодах
int used; // вышло карт

int critical;   // критичная точка
                // возвращаем вышедшие неиспользуемые карты
                // высчитывается при задании num_of_decks

int num_of_players; //количество игроков
Player *pl; // список игроков

public:
//Game();
Game(Player* ls, int num_of_pl, int num_of_dec);
~Game();

Card DrawACard() const;

void BackCards();

void process();

void finish();


bool IsCritical() const;

};
