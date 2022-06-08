#pragma once
#include "Population.h"
#include "SudokuFactory.h"
#include "SudokuFitness.h"
#include "SudokuOffspring.h"

struct compare {
  bool operator()(Sudoku* &a, Sudoku* &b) {
    SudokuFitness fit;
    return fit.howFit(*a) < fit.howFit(*b);
  }
};

class SudokuPopulation : public Population {
private:
  SudokuFitness* fitness;
  SudokuFactory* factory;
  SudokuOffspring* reproduction; 

  bool fixedValue[9][9];

  int popSize;

   priority_queue<Sudoku *, vector<Sudoku *>, compare> members;
//priority_queue<Puzzle, vector<Puzzle>, compare> members;

public:
  // SudokuPopulation(int population, int generations, Puzzle &puzzle);
  SudokuPopulation(int population, Sudoku* sudoku);

  priority_queue<Sudoku *, vector<Sudoku *>, compare> getMembers();

  SudokuFitness* getFitness();
  SudokuFactory* getFactory();
  SudokuOffspring* getReproduction();
  

  void cull(int) override;
  void newGeneration() override;
  int bestFitness() override;
  Sudoku * bestIndividual() override;
};