#include <iostream>
#include <vector>
#include "Game.h"

int main (int argc, char ** argv)
{
    std::vector<Player *> pl;

    Player *p5c = new StrategyOf5Cards;
    Player *s17s = new StrategyOf17Score;
    Player *s19s = new StrategyOf19Score;
    Player *s21s = new StrategyOf21Score;

    pl.push_back(p5c);
    pl.push_back(s17s);
    pl.push_back(s19s);
    pl.push_back(s21s);

    Game g(pl, 1);
    g.finish();

    delete p5c;
    delete s17s;

    return 0;
}
