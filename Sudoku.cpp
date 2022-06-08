#include "Sudoku.h"
#include <random>

Sudoku::Sudoku() {
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      grid[i][j] = 0;
    }
  }
}

bool Sudoku::getFixedValue(int x, int y){
  return fixedValue[x][y];
}

int Sudoku::getValue(int x, int y){
  return grid[x][y];
}
void Sudoku:: setValue(int x, int y, int value){
  grid[x][y] = value;
}

void Sudoku::read(string sudokuNums){
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

  for(char& c : sudokuNums){
    if (x > 9) {
      y++;
      x = 0;
      if(y > 9){
        break;
      }
    }
    if (isdigit(c)) {
      grid[x][y] = c-'0';
      //this->print(cout);
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



ostream& Sudoku::print(ostream& output){
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