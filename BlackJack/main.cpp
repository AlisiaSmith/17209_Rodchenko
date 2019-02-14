#include <iostream>
#include <vector>
#include "Game.h"
#include "Factory.h"



int main (int argc, char ** argv)
{
    std::vector<Player *> pl;

 //   Player *p5c = new StrategyOf5Cards;
 //   Player *s17s = new StrategyOf17Score;
 //   Player *s19s = new StrategyOf19Score;
 //   Player *s21s = new StrategyOf21Score;
for(int i = 1; i < argc; i++)
{
    pl.push_back(Factory<std::string,  Player* (*)()>::getInstance()->createPlayerByID(argv[i]));
}

    Game g(pl, 1);
    g.finish();


    return 0;
}
