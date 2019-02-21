#pragma once

#include <ctime>
#include <fstream>
#include "cell.h"

class Field
{
private:

  Cell **celles;

  int widht;
  int height;

  int lives;

public:
  //Field();

  Field(int w, int h);
  ~Field();

  void clear();
  void random();
  void save();
  void load();
  void step();
  void computation();
  void click(int x, int y);
  Cell getCell(int x, int y) const;

  int getWidht() const;
  int getHeight() const;

  Cell* operator[](int i) const;

  bool isNotEnd() const;

private:

  void operator=(const Field &f);

};
