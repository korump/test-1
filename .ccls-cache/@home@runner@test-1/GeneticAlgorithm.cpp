#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(int popSize, int maxGen) {
  Sudoku *sudoku = new Sudoku();

  cout << "Enter Sudoku: ";
  cin >> sudoku;

  //Debug
  cout << "Original: \n";
  cout << sudoku;  
  
  SudokuPopulation *population = new SudokuPopulation(popSize, sudoku);
  SudokuOffspring *reproduction = population->getReproduction();
  SudokuFitness *fitness = population->getFitness();

  // Generates first generation based off initial Sudoku puzzle
  for (int i = 0; i < popSize; i++) {
    Sudoku *curSudoku = reproduction->makeOffspring(*sudoku);
    population->getMembers().push(curSudoku);

    //Debug
    cout << "Test: \n";
    cout << curSudoku;
    cout << "\nFitness" << fitness->howFit(*curSudoku) << '\n';
    
    if (fitness->howFit(*curSudoku) == 0) {
      cout << "Solution:\n" << fitness->howFit(*curSudoku); 
      cout << curSudoku;
    }
  }

  // Sets mutation probability to 5% for future generations

  reproduction->setProb(5);

  // for (int i = 1; i <= maxGen; i++) {
  //   int bestFit = population->bestFitness();
  //   if (bestFit == 0) {
  //     cout << "Best Individual\n";
  //     cout << population->bestIndividual();
  //     break;
  //   }
  //   if (i == maxGen) {
  //     cout << "Best Individual\n";
  //     cout << population->bestIndividual();
  //     break;
  //     population->cull(90);
  //     population->newGeneration();
  //   }
  // }
}
