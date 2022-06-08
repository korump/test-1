#include "SudokuFactory.h"

Sudoku* SudokuFactory::createPuzzle(Puzzle& puzzle) {
  Sudoku sudoku = dynamic_cast<Sudoku&>(puzzle);
  return rep.makeOffspring(sudoku);
}