#include "Fitness.h"
#include "Puzzle.h"
#include "PuzzleFactory.h"
#include "Reproduction.h"
#include <queue>
#include <vector>

#pragma once

class Population {
private:
  Fitness *fitness;
  PuzzleFactory *factory;
  Reproduction *reproduction;

// protected:
//   int popSize;

//   priority_queue<Puzzle *, vector<Puzzle *>, compare> members;

public:
  Population();
  virtual ~Population();

  virtual void cull(int) = 0;
  virtual void newGeneration() = 0;
  virtual int bestFitness() = 0;
  virtual Puzzle *bestIndividual() = 0;
};