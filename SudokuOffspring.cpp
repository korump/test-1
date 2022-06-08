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

// const to no const
Sudoku *SudokuOffspring::makeOffspring(Puzzle &sudoku) {
  Sudoku *newPuzzle = new Sudoku(sudoku.getData());
  // copy the old puzzle to new puzzle and mutating the value by using the
  // rand() value.
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (newPuzzle->getFixedValue(i, j) == false) {
        if (rand() % 100 < probability) {
          newPuzzle->setValue(i, j, (rand() % 9 + 1));
        }
        // } else {
        //   int curIndex = sudokuPuzzle->getValue(i, j);
        //   newPuzzle->setValue(i, j, curIndex);
        // }
      }
    }
  }
  return newPuzzle;
}