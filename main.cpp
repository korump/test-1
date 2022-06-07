#include "Puzzle.h"
#include "Sudoku.h"
#include "GeneticAlgorithm.h"
#include <iostream>

int main(int argc, char *argv[]) {
  int populationSize = atoi(argv[1]);
  int maxGeneration = atoi(argv[2]);

  GeneticAlgorithm(populationSize, maxGeneration);
}