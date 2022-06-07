#include "Population.h"

Population::Population(int population, int generations){
  popSize = population;
  generation = 0;
  generationLimit = generations;
}