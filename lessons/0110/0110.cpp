#include <iostream>
#include <vector>

//doctor memory

class Unit
{
public:
    virtual void  move() = 0;
    virtual ~Unit() {};
};

class SeidgTank : public Unit
{
public:
    SeidgTank() : i(new int[100500]) {}
    ~SeidgTank() {
        std::cout <<"" << std::endl;
        delete []i;
    }
    void move() override
    {
       std::cout << "SeingTank::move()" << std::endl;
    }
private:
    int *i;
};

class Zealot : public Unit
{
public:
    void move() override
    {
        std::cout << "Zealot::move" << std::endl;
    }
};


class Marine : public Unit
{
public:
    void move() override
    {
        std::cout << "Marine::move" << std::endl;
    }

};

void moveAllUnits(std::vector<Unit*> units)
{
    for(std::vector<Unit *>::iterator it = units.begin(); it != units.end())
        (*it)->move();

    // for(Unit * u : Units) {
    // u->move();
    // }
}

int main() {
   std::vector<Unit *> units;
   units.push_back(new Zealot);
   units.push_back(new Marine);
   units.push_back(new SeidgTank);
   moveAllUnits(units);


 //  for(size_t i = 0u; i< unit.size) че-то такое
//   for(Unit *u : units)
//   {
//       delete u;
//   }
    return 0;
}