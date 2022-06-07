#include "SudokuOffspring.h"
#include "Sudoku.h"
#include <ctime>
#include <random>

// void SudokuOffspring::checkFixed(Sudoku &sudoku) {

//   srand(time(0));
//   for (int i = 0; i < 9; i++) {
//     for (int j = 0; j < 9; j++) {
//       int curIndex = sudoku.getValue(i, j);
//       // if(curIndex == 0){
//       //   valueChange[i][j] = false;
//       // }
//       // else{
//       //   valueChange[i][j] = true;
//       // }
//       valueChange[i][j] = (curIndex != 0);
//     }
//   }
// }

void SudokuOffspring::setProb(int prob) { probability = prob; }

Sudoku *SudokuOffspring::makeOffspring(const Puzzle &puzzle) {
  Sudoku sudokuPuzzle = dynamic_cast<Sudoku &>(puzzle);

  Sudoku *newPuzzle = new Sudoku();

  // copy the old puzzle to new puzzle and mutating the value by using the
  // rand() value.
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if ((sudokuPuzzle.getFixedValue(i, j) == false) && (rand() % 100 < probability)) {
        newPuzzle->setValue(i, j, (rand() % 9 + 1));
      } else {
        int curIndex = sudokuPuzzle.getValue(i, j);
        newPuzzle->setValue(i, j, curIndex);
      }
    }
  }
  return newPuzzle;
}