#include "GeneticAlgorithm.h"
#include "Puzzle.h"
#include "Sudoku.h"
#include <iostream>

int main(int argc, char *argv[]) {
     // int populationSize = atoi(argv[1]);
     // int maxGeneration = atoi(argv[2]);

   //Sudoku* test = new Sudoku();
  
priority_queue<Puzzle*, vector<Puzzle*>, compare> temp;
  
  string sudone = "500467309903810427174203000231976854857124090496308172000089260782641005010000708";

  string sudtwo = "409806701001307200030009024500030680090000050026080007300100020004603900908402503";
  
  Sudoku* test = new Sudoku();
  test->read(sudone);
  test->findFitness();
  cout << test;
  temp.push(test);
   //GeneticAlgorithm(populationSize, maxGeneration);

  test->read(sudtwo);
  test->findFitness();
  cout << test;
  temp.push(test);

  cout << "The top of prioity queue:" <<endl;
  cout<< temp.top();
  //cout << test;

  
  // Sudoku* testtwo = new Sudoku();
  // cin >> testtwo;
  // test->findFitness();
  // cout<< test;


  // Sudoku* testtwo = new Sudoku();

  // cin >>
  // Sudoku *testPuzzle = new Sudoku();
  
  // cout << "Enter Sudoku: ";
  // cin >> testPuzzle;

  // cout << testPuzzle;
}