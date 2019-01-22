#include "field.h"

Field::Field(int w, int h) : widht(w), height(h), lives(0)
{
  celles = new Cell* [widht];
  for(int i = 0; i < widht; i++)
    celles[i] = new Cell [height];
}

Field::~Field()
{
   for(int i = 0; i < widht; i++)
     delete[] celles[i];

   delete[] celles;
}

int Field::getHeight() const  { return height; }
int Field::getWidht() const  { return widht; }
Cell* Field::operator[](int i) const { return celles[i % widht]; }

void Field::clear()
{
  if(!lives) return;

  for(int i = 0; i < widht; i++)
    for(int j = 0; j < height; j++)
    {
      celles[i][j].now = false;
      celles[i][j].prev = false;
      celles[i][j].next = false;
    }

  lives = 0;
}

void  Field::random()
{
  Field::clear();

  //srand(time(0));
  int count = rand() % (widht * height / 3) + (widht + height) / 2;

  for(int i = 0; i < count; i++)
  {
    int x = rand() % widht;
    int y = rand() % height;
    click(x, y);
  }
}

void Field::save()
{
  std::ofstream fout;
  fout.open("SaevedField.life", std::ios::out | std::ios::binary);

  fout << widht << std::endl;

  fout << height << std::endl;

    for(int i = 0; i < widht; i++)
    {
       for(int j = 0; j < height; j++)
       if(celles[i][j].now)
          fout << 1 << " ";
       else
          fout << 0 << " ";
       fout << std::endl;
    }

    fout.close();
}

void Field::load()
{
  std::ifstream fin;
  fin.open("SaevedField.life", std::ios::in | std::ios::binary)  ;
  if(!fin)  return;

  int new_w;
  int new_h;

  fin >> new_w >> new_h;

  Field f(new_w, new_h);

  for (int i = 0; i < widht; i++)
    for(int j = 0; j < height; j++)
    {
        int t;
        fin >> t;
        if(t)
            f[i][j].now = true;
        else
            f[i][j].now = false;
        f[i][j].prev = false;
        f[i][j].next = false;
    }

  fin.close();

  *this = f;
}

void Field::operator=(const Field& f)
{

  if (this != &f)
  {
    if(!(widht == f.getWidht() && height == f.getHeight()))
    {
      for(int i = 0; i < widht; i++)
        delete[] celles[i];
      delete[] celles;

      widht = f.getWidht();
      height = f.getHeight();

      celles = new Cell* [widht];
      for(int i = 0; i < widht; i++)
        celles[i] = new Cell [height];
    }

    lives = 0;
    for (int i = 0; i < widht; i++)
      for(int j = 0; j < height; j++)
      {
        celles[i][j].now = f[i][j].now;
        celles[i][j].prev = f[i][j].prev;
        celles[i][j].next = f[i][j].next;

        if (celles[i][j].now) lives++;
      }

  }
}

void Field::step()
{
  computation();

  lives = 0;

  for(int i = 0; i < widht; i++)
    for(int j = 0; j < height; j++)
    {
      celles[i][j].prev = celles[i][j].now;
      celles[i][j].now = celles[i][j].next;
      if(celles[i][j].now) lives++;
    }

}

void Field::computation()
{
  for(int x = 0; x < widht; x++)
      for(int y = 0; y < height; y++)
      {
          int count = 0;
          if (celles[(x-1+widht) % widht][(y-1+height) % height].now) count++;
          if (celles[(x-1+widht) % widht][y].now) count++;
          if (celles[(x-1+widht) % widht][(y+1) % height].now) count++;
          if (celles[x][(y+1) % height].now) count++;
          if (celles[(x+1) % widht][(y+1) % height].now) count++;
          if (celles[(x+1) % widht][y].now) count++;
          if (celles[(x+1) % widht][(y-1+height) % height].now) count++;
          if (celles[x][(y-1+height) % height].now) count++;

          if(count == 3 | (celles[x][y].now && count == 2))
              celles[x][y].next = true;
          else
              celles[x][y].next = false;
      }
}

void Field::click(int x, int y)
{
    celles[x][y].now = !celles[x][y].now;
    if(celles[x][y].now) lives++;
    else lives--;
}

Cell Field::getCell(int x, int y) const
{
    return celles[x][y];
}

bool Field::isNotEnd() const
{
    for (int i = 0; i < widht; i++)
        for(int j = 0; j < height; j++)
            if(celles[i][j].next != celles[i][j].prev) return true;
    return false;
}
