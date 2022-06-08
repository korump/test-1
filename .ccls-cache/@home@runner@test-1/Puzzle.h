#include <iostream>
#pragma once

using namespace std;

class Puzzle{
  public:
    ~Puzzle(){};
    friend void operator<<(ostream&, Puzzle*);
    friend void operator>>(istream&, Puzzle*);

    virtual void read(string) = 0;
    virtual ostream& print(ostream&) = 0;
};