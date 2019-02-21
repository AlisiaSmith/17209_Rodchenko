#pragma once

#include <string>

#include "Card.h"


#define MAX_CARDS 12

class Player
{
protected:

    int score;
    Card *list;
    int count;
    int wins;

public:
    Player();
     virtual ~Player();

     virtual bool ShoudTakeNext();
     virtual std::string WhoAmI() const;

    int GetScore()const;
    int GetCount()const;

    void PutCard(Card& a);

    void ClearList();

    void lose();
    void won();

};
