#pragma once

#include <vector>
#include <iostream>
#include <ctime>

#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "Strategy.h"

class Game
{
private:

Deck *d;                // игровые коллоды
int num_of_decks;       // их количесво
size_t count;           // количество карт во всех коллодах
int used;               // вышло карт
int hold;               // карт на руках

int critical;           // критичная точка
                        // возвращаем вышедшие неиспользуемые карты
                        // высчитывается при задании num_of_decks

std::vector<Player*> pl;             // список игроков

public:
//Game();
Game(std::vector<Player*> ls, int num_of_dec); // инициализация игры
~Game();

Card DrawACard();       // вытянуть карту

void BackCards();       // вернуть вышедшие карты в коллоду

void process();         // сама игра

void finish();          // круг закончен


bool IsCritical() const;      // критическое колличество карт в коллоде
                              // осталась только треть карт

};
