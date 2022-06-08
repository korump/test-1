#include "Reproduction.h"
#pragma once

class PuzzleFactory{
  private:
    Reproduction* rep;
  public:
    virtual ~PuzzleFactory(){};

    virtual Puzzle* createPuzzle(Puzzle&) = 0;
};