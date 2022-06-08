#include "SudokuFactory.h"

SudokuFactory::SudokuFactory() {
  rep = new SudokuOffspring();
}

Sudoku* SudokuFactory::createPuzzle(Puzzle& puzzle) {
  Sudoku sudoku = dynamic_cast<Sudoku&>(puzzle);
  return dynamic_cast<Sudoku*>(rep->makeOffspring(sudoku));
}