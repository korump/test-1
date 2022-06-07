#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(int popSize, int maxGen) {
  Sudoku *sudoku = new Sudoku();
  cin >> sudoku;

  SudokuPopulation *population = new SudokuPopulation(popSize, maxGen, sudoku);
  SudokuOffspring* reproduction = population->getReproduction();
  SudokuFitness* fitness = population->getFitness();
  
  // Generates first generation based off initial Sudoku puzzle
  for (int i = 0; i < popSize; i++) {
    Sudoku* curSudoku = reproduction->makeOffspring(*sudoku);
    population->getMembers().push(curSudoku);

    if(fitness->howFit(*curSudoku) == 0){
      cout << curSudoku << " " << fitness->howFit(*curSudoku) << "Best Puzzle";
    }
  }

  // Sets mutation probability to 5% for future generations
  reproduction->setProb(5);

  for(int i = 1; i <= maxGen; i++){
    int bestFit = population->bestFitness();
    if(bestFit == 0){
      cout << population->bestIndividual() << "Best Individual"; 
      break;
    }
    if(i == maxGen){
      cout << population->bestIndividual() << "Best Individual";
      break;
    }
    population->cull(90);
    population->newGeneration();
  }
}
