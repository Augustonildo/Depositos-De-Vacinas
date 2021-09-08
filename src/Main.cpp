#include <iostream>
#include <fstream>
#include <string>
#include "Arvore.hpp"
using namespace std;

void desalocaEspacoListaVilas(Vila** listaVilas, int numeroVilas){
    for (int i = 0; i < numeroVilas; i++)
    {
        delete(listaVilas[i]);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        cout << "Os parametros necessarios para a execução não foram informados. Tente novamente." << endl;
        return -1;
    }

    string tipoTarefa = argv[1];
    ifstream arquivoEntrada(argv[2]);
    streambuf *cinbuf = cin.rdbuf(arquivoEntrada.rdbuf()); //Alterando buffer de leitura para o arquivo de entrada

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

    cin.rdbuf(cinbuf); //Reinicializando o buffer de leitura
    desalocaEspacoListaVilas(listaVilas, numeroVilas);
    return 0;
}