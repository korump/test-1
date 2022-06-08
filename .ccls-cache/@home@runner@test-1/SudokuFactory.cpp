#include "SudokuFactory.h"

SudokuFactory::SudokuFactory() {
  SudokuOffspring* sudOff = new SudokuOffspring();
  rep = sudOff;
}

Sudoku* SudokuFactory::createPuzzle(Puzzle& puzzle) {
  Sudoku sudoku = dynamic_cast<Sudoku&>(puzzle);
  return dynamic_cast<Sudoku*>(rep->makeOffspring(sudoku));
}