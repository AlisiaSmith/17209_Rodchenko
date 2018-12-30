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

    void PutCard(Card& a);

    void ClearList();

};
