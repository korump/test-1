#include "Puzzle.h"
#pragma once

class Reproduction{
  public:
    virtual ~Reproduction(){};
    Puzzle* makeOffspring( Puzzle&);
}; 