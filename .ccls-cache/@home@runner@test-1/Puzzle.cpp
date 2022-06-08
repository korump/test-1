#include "Puzzle.h"

void operator<<(ostream& output, Puzzle* puzzle) { 
  puzzle->print(output); 
  }

void operator>>(istream &input, Puzzle* puzzle) {
  string data;
  input >> data;
  puzzle->read(data);
}