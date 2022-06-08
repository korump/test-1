#pragma once

#include "Puzzle.h"

class Fitness {
public:
  virtual ~Fitness(){};
  virtual int howFit( const Puzzle &puzzle) const = 0;
};