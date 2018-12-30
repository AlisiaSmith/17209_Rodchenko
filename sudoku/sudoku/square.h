#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>

class Square
{
private:
    int sq[9][9];
public:
    Square();
    ~Square();
    void mix();
    void print();
};

#endif // SQUARE_H
