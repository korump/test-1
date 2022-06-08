#pragma once
#include "Reproduction.h"
#include "Sudoku.h"

class SudokuOffspring : public Reproduction {
private:
  bool valueChange[9][9];
  void checkFixed(Sudoku &);
  int probability = 5;

public:
  Sudoku *makeOffspring(Puzzle&) override;
  void setProb(int);
};