#include "SudokuFitness.h"

int SudokuFitness::howFit(Puzzle &puzzle) {
  Sudoku sudoku = dynamic_cast<const Sudoku &>(puzzle);
  
  return sudoku.getFitness();
}
