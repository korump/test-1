#include <iostream>
#pragma once

using namespace std;

class Puzzle {
protected:
  string data;
  int fitness = 0;

public:
  ~Puzzle(){};
  friend void operator<<(ostream &, Puzzle *);
  friend void operator>>(istream &, Puzzle *);

  string getData() const { return data; };

  virtual void read(string) = 0;
  virtual ostream &print(ostream &) = 0;

  virtual void findFitness() = 0;
};