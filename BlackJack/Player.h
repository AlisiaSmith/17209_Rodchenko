#pragma once

#include "Card.h"

#define MAX_CARDS 12

class Player
{
private:

    int score;
    Card *list;
    int count;

public:
    Player();
    ~Player();

    bool DoesHaveThisCard(Card& a) const;

    int GetScore()const;

    void PutCard(Card& a);

    void ClearList();

};
