#pragma once
#include "PuzzleFactory.h"
#include "SudokuOffspring.h"
#include "Sudoku.h"

class SudokuFactory : public PuzzleFactory{
  public:
    SudokuFactory();
    Sudoku* createPuzzle(Puzzle&) override;
};