#pragma once
#include "Population.h"
#include "SudokuFactory.h"
#include "SudokuFitness.h"
#include "SudokuOffspring.h"

struct compare {
  bool operator()(Puzzle &a, Puzzle &b) {
    Fitness fit;
    return fit.howFit(a) < fit.howFit(b);
  }
};

class SudokuPopulation : public Population {
private:
  SudokuFitness* fitness;
  SudokuFactory* factory;
  SudokuOffspring* reproduction; 

  bool fixedValue[9][9];

  int popSize;

  // priority_queue<Puzzle *, vector<Puzzle *>, compare> members;
priority_queue<Puzzle, vector<Puzzle>, compare> members;

public:
  // SudokuPopulation(int population, int generations, Puzzle &puzzle);
  SudokuPopulation(int population, int generations, Sudoku* sudoku);

  priority_queue<Puzzle, vector<Puzzle>, compare> getMembers();

  SudokuFitness* getFitness();
  SudokuFactory* getFactory();
  SudokuOffspring* getReproduction();
  

  void cull(int) override;
  void newGeneration() override;
  int bestFitness() override;
  Puzzle *bestIndividual() override;
};