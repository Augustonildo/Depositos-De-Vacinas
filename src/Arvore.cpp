#include <iostream>
#include "Arvore.hpp"

Arvore::Arvore(){}

Arvore::Arvore(Vila* raiz, int numeroVilas){
  this->raiz = raiz;
  this->numeroVilas = numeroVilas;
  this->coberturaMinimaDeVilas = 0;
}

Vila* Arvore::getRaiz(){
  return this->raiz;
}

int Arvore::getCoberturaMinimaDeVilas(){
    int vilasCobertas[numeroVilas], vilasSelecionadas[numeroVilas];
    for (int i = 0; i < numeroVilas; i++){
        vilasCobertas[i] = 0;
        vilasSelecionadas[i] = 0;
    }

    this->encontraCoberturaMinimaPorDfs(this->raiz, NULL, vilasCobertas, vilasSelecionadas);
    return this->coberturaMinimaDeVilas;
}

void Arvore::encontraCoberturaMinimaPorDfs(Vila* vila, Vila* vilaMae, int* vilasCobertas, int* vilasSelecionadas)
{
    vilasCobertas[vila->getId()] = 1;
    int numeroVizinhas = vila->getNumeroVizinhas();
    if(!numeroVizinhas) 
        return;

    Vila** listaVizinhas = vila->getVilasVizinhas();
    for (int i = 0; i < numeroVizinhas; i++)
    {
        if(!vilasCobertas[listaVizinhas[i]->getId()]){
            this->encontraCoberturaMinimaPorDfs(listaVizinhas[i], vila, vilasCobertas, vilasSelecionadas);
            if(!vilasSelecionadas[listaVizinhas[i]->getId()] && !vilasSelecionadas[vila->getId()]){
                coberturaMinimaDeVilas++;
                vilasSelecionadas[vila->getId()] = 1;
            }
        }
    }
}
