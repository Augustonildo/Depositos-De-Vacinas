#include <iostream>
#include <string>
#include "Arvore.hpp"
using namespace std;

void desalocaEspacoListaVilas(Vila** listaVilas, int numeroVilas){
    for (int i = 0; i < numeroVilas; i++)
    {
        delete(listaVilas[i]);
    }
}

int main()
{
    // TODO: implementar leitura tipoTarefa
    // string tipoTarefa;
    // cin >> tipoTarefa;
    int numeroVilas, numeroCaminhos;
    cin >> numeroVilas >> numeroCaminhos;

    Vila* listaVilas[numeroVilas];
    for (int i = 0; i < numeroVilas; i++)
    {
        listaVilas[i] = new Vila(i, numeroVilas);
    }

    int verticeA, verticeB;
    for (int i = 0; i < numeroCaminhos; i++)
    {
        cin >> verticeA >> verticeB;
        listaVilas[verticeA]->setVilaVizinha(listaVilas[verticeB]);
        listaVilas[verticeB]->setVilaVizinha(listaVilas[verticeA]);
    }

    Arvore arvore = Arvore(listaVilas[0], numeroVilas);
    cout << arvore.getCoberturaMinimaDeVilas() << endl;

    desalocaEspacoListaVilas(listaVilas, numeroVilas);
    return 0;
}