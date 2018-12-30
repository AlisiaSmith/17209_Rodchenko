#include "square.h"

Square::Square()
{
    for(int i = 0; i < 3; i ++)
        for(int k = 3 * i; k < 3 * i + 3; k ++)
        {
            for(int j = 0; j < 9; j ++)
                sq[k][j] = (j + i + k * 3) % 9 + 1;
        }
}

Square::~Square() {}

void Square::mix(){
for(int i = 0; i < 3; i++)
    {
        int iter = rand() % 7;
        for (int j = 0; j < iter; j++)
        {
            int a = rand() % 3;
            int b = rand() % 3;
            if (a != b)
                for (int k = 0; k < 9; k++)
                std::swap(sq[i * 3 + a][k], sq[i * 3 + b][k]);
        }
    }

    for(int i = 0; i < 3; i++)
    {
        int iter = rand() % 5;
        for (int j = 0; j < iter; j++)
        {
            int a = rand() % 3;
            int b = rand() % 3;
            if (a != b)
                for (int k = 0; k < 9; k++)
                std::swap(sq[k][i * 3 + a], sq[k][i * 3 + b]);
        }
    }
}

void Square::print()
{
    for (int i = 0; i < 9; i++)
    {
        for(int  j = 0; j < 9; j ++)
            std::cout << sq[i][j] << " " ;
        std::cout << std::endl;

    }
}

