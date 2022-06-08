#include "Puzzle.h"
#include "Sudoku.h"
#include "GeneticAlgorithm.h"
#include <iostream>

int main(int argc, char *argv[]) {
    int populationSize = atoi(argv[1]);
    int maxGeneration = atoi(argv[2]);

  GeneticAlgorithm(populationSize, maxGeneration);

  //Sudoku* test = new Sudoku();

  //cout<< "Enter Suodku";

 //  string test;
 //  test = "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789";
 // // cin >> test;

 //  Sudoku testPuzzle;

 //  testPuzzle.read(test);
 //  //testPuzzle >> test;

  
 //  testPuzzle.print(cout);
}