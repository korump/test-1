#pragma once
#include "Puzzle.h"
using namespace std;


class Sudoku : public Puzzle {
private:
  int grid[9][9];
  bool fixedValue[9][9];
public:
  Sudoku();
  ~Sudoku(){};

  bool getFixedValue(int, int);
  int getValue(int, int);
  void setValue(int, int, int);

  void read(string) override;
  ostream &print(ostream&) override;
};