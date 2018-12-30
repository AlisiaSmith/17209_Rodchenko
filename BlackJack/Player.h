#pragma once

#include "Card.h"

#define MAX_CARDS 12

class Player
{
protected:

    int score;
    Card *list;
    int count;

public:
    Player();
     virtual ~Player();

     virtual bool ShoudTakeNext();

    int GetScore()const;
    int GetCount()const;

    void PutCard(Card& a);

    void ClearList();

    void lose();
    void won();

};
