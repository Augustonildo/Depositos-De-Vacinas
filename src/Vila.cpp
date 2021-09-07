#include <iostream>

#include "Vila.hpp"

Vila::Vila(){}

Vila::Vila(int id, int maxVizinhos){
  this->id = id;
  this->numeroVizinhas = 0;
  this->vilasVizinhas = (Vila **)malloc(maxVizinhos * sizeof(Vila*));
}

Vila::~Vila(){
  free(this->vilasVizinhas);
}

int Vila::getId(){
    return this->id;
}

int Vila::getNumeroVizinhas(){
    return this->numeroVizinhas;
}

Vila** Vila::getVilasVizinhas(){
  return this->vilasVizinhas;
}

void Vila::setVilaVizinha(Vila* vila){
  this->vilasVizinhas[numeroVizinhas] = vila;
  this->numeroVizinhas++;
}