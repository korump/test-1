#include "Sudoku.h"
#include <random>

Sudoku::Sudoku() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      grid[i][j] = 0;
    }
  }
}

bool Sudoku::getFixedValue(int x, int y) { return fixedValue[x][y]; }

int Sudoku::getValue(int x, int y) { return grid[x][y]; }
void Sudoku::setValue(int x, int y, int value) { grid[x][y] = value; }

void Sudoku::read(string sudokuNums) {
  int x = 0;
  int y = 0;

  // while (y <= 9) {
  //   if (x > 9) {
  //     y++;
  //     x = 0;
  //   }
  //   c = sudokuNums.get();
  //   if (isdigit(c)) {
  //     grid[x][y] = c;
  //     x++;
  //   }
  // }

  for (char &c : sudokuNums) {
    if (x > 8) {
      y++;
      x = 0;
      if (y > 8) {
        break;
      }
    }
    if (isdigit(c)) {
      grid[y][x] = c - '0';
      x++;
    }
  }

  //   for (int i = 0; i < 9; i++) {
  //     for (int j = 0; j < 9; j++) {
  //       int curVal = getValue(i, j);
  //       fixedValue[i][j] = (curVal != 0);
  //     }
  //   }
  // }
}

ostream &Sudoku::print(ostream &output) {
  string format = "+-------+-------+-------+\n";
  output << format;
  for (int i = 0; i < 9; i++) {
    output << '|';
    for (int j = 0; j < 9; j++) {
      output << " " << grid[i][j];
      if (j % 3 == 2) {
        output << " " << '|';
      }
    }
    if (i % 3 == 2) {
      output << '\n' << format;
    } else {
      output << '\n';
    }
  }
  return output;
}

void Sudoku::findFitness() {
  vector<int> existValues;

  // Check each row for conflicts
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int curVal = getValue(i, j);
      if (find(begin(existValues), end(existValues), curVal) ==
              end(existValues) &&
          curVal != 0) {
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
      // int curVal = sudoku.getValue(j, i);
      int curVal = 5;
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
          // int curVal = sudoku.getValue(i, j);
          int curVal = 5;
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
}

int Sudoku::getFitness() { return fitness; }