#include "Fitness.h"
#include "Puzzle.h"
#include "PuzzleFactory.h"
#include "Reproduction.h"
#include <queue>
#include <vector>

#pragma once

struct compare {
  bool operator()(Puzzle &a, Puzzle b) {
    Fitness *fit;
    return fit->howFit(a) < fit->howFit(b);
  }
};

class Population {
private:
  Fitness *fitness;
  PuzzleFactory *factory;
  Reproduction *reproduction;

protected:
  int popSize;

  priority_queue<Puzzle *, vector<Puzzle *>, compare> members;

public:
  Population();
  virtual ~Population();

  virtual priority_queue<Puzzle *, vector<Puzzle *>, compare> getMembers() = 0;

  virtual void cull(int) = 0;
  virtual void newGeneration() = 0;
  virtual int bestFitness() = 0;
  virtual Puzzle *bestIndividual() = 0;
};