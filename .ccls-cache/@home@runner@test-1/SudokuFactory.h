#pragma once
#include "PuzzleFactory.h"
#include "SudokuOffspring.h"
#include "Sudoku.h"

class SudokuFactory : public PuzzleFactory{
  private:
    SudokuOffspring rep;
  public:
    Sudoku* createPuzzle(Puzzle&) override;
};