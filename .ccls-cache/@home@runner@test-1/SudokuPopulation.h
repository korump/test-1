#pragma once
#include "Population.h"
#include "SudokuFactory.h"
#include "SudokuFitness.h"
#include "SudokuOffspring.h"

class SudokuPopulation : public Population {
private:
  SudokuFitness* fitness;
  SudokuFactory* factory;
  SudokuOffspring* reproduction; 

  bool fixedValue[9][9];

public:
  // SudokuPopulation(int population, int generations, Puzzle &puzzle);
  SudokuPopulation(int population, int generations, Sudoku* sudoku);

  priority_queue<Puzzle *, vector<Puzzle *>, compare> getMembers() override;

  SudokuFitness* getFitness();
  SudokuFactory* getFactory();
  SudokuOffspring* getReproduction();
  

  void cull(int) override;
  void newGeneration() override;
  int bestFitness() override;
  Puzzle *bestIndividual() override;
};