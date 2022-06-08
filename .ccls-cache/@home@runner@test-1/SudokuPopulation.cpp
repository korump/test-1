#include "SudokuPopulation.h"

SudokuPopulation::SudokuPopulation(int population, Sudoku *sudoku) {
  popSize = population;

  // for (int i = 0; i < 9; i++) {
  //   for (int j = 0; j < 9; j++) {
  //     int curVal = sudoku->getValue(i, j);
  //     fixedValue[i][j] = (curVal != 0);
  //   }
  // }

  for (int i = 0; i < popSize; i++) {
    Puzzle *newSudoku = factory.createPuzzle(*sudoku);
    members.push(newSudoku);
  }
}

SudokuFitness SudokuPopulation::getFitness() { return fitness; }

SudokuFactory SudokuPopulation::getFactory() { return factory; }

SudokuOffspring SudokuPopulation::getReproduction() { return reproduction; }

priority_queue<Puzzle*, vector<Puzzle*>, compare> SudokuPopulation::getMembers() {
  return members;
}

void SudokuPopulation::cull(int x) {
  priority_queue<Puzzle*, vector<Puzzle*>, compare> temp;

  int keepCount = 100 - x;

  for (int i = 0; i < keepCount; i++) {
    temp.push(members.top());
    members.pop();
  }
  members = temp;
}

void SudokuPopulation::newGeneration() {
  priority_queue<Puzzle*, vector<Puzzle*>, compare> temp = members;

  Puzzle *curSudoku;
  int toFill = popSize - members.size();
  int offspringCount = toFill / members.size();

  for (int i = 0; i < toFill; i += 10) {
    for (int i = 0; i < offspringCount; i++) {
      members.push(reproduction.makeOffspring(*temp.top()));
      temp.pop();
    }
  }
}

int SudokuPopulation::bestFitness() { return fitness.howFit(*members.top()); }

Puzzle* SudokuPopulation::bestIndividual() {
  return members.top(); 
}
