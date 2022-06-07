#pragma once
#include "Fitness.h"
#include "Sudoku.h"

#include <algorithm>
#include <vector>

using namespace std;

class SudokuFitness : public Fitness {
public:
  int howFit(const Puzzle &puzzle) const override;
};