#include "SudokuFitness.h"

int SudokuFitness::howFit(const Puzzle &puzzle) const {
  Sudoku sudoku = dynamic_cast<const Sudoku &>(puzzle);
  int fitness = 0;
  vector<int> existValues;

  // Check each row for conflicts
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int curVal = sudoku.getValue(i, j);
      if (find(begin(existValues), end(existValues), curVal) ==
          end(existValues) && curVal != 0) {
        existValues.push_back(curVal);
      } else {
        fitness++;
      }
    }
    existValues.clear();
  }

  // Check each column for conflicts
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int curVal = sudoku.getValue(j, i);
      if (find(begin(existValues), end(existValues), curVal) ==
          end(existValues)) {
        existValues.push_back(curVal);
      } else {
        fitness++;
      }
    }
    existValues.clear();
  }

  // Check each 3x3 block for conflicts
  for (int row = 0; row < 9; row += 3) {
    for (int col = 0; col < 9; col += 3) {
      for (int i = row; i < row + 3; i++) {
        for (int j = col; i < col + 3; j++) {
          int curVal = sudoku.getValue(i, j);
          if (find(begin(existValues), end(existValues), curVal) ==
              end(existValues)) {
            existValues.push_back(curVal);
          } else {
            fitness++;
          }
        }
      }
      existValues.clear();
    }
  }

  return fitness;
}