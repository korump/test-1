#include "Puzzle.h"

void Puzzle::operator<<(ostream& output) { 
  print(output); 
  }

void operator>>(istream &input, Puzzle* puzzle) {
  string data;
  input >> data;
  puzzle->read(data);
}