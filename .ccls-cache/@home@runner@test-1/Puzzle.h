#include <iostream>
#pragma once

using namespace std;

class Puzzle{
  public:
    ~Puzzle(){};
    void operator<<(ostream&);
    friend void operator>>(istream&, Puzzle*);

    virtual void read(string) = 0;
    virtual ostream& print(ostream&) = 0;
};