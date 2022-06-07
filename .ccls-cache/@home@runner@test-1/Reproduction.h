#include "Puzzle.h"
#pragma once

class Reproduction{
  public:
    virtual ~Reproduction();
    virtual Puzzle* makeOffspring(const Puzzle&);
};