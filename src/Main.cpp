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

void execucaoTarefa1(int numeroVilas, int numeroCaminhos){
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
}

void zerarValoresMatrizInt(int** matriz, int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matriz[i][j] = 0;
}

int **alocarEspacoMatrizInt(int m, int n)
{
    int **matriz = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        matriz[i] = (int *)malloc(n * sizeof(int));

    zerarValoresMatrizInt(matriz, m, n);
    return matriz;
}

void limparEspacoMatriz(int **matriz, int m)
{
    for (int i = 0; i < m; i++)
        free(matriz[i]);
    free(matriz);
}

void execucaoTarefa2(int numeroVilas, int numeroCaminhos){
    int** matrizArestas = alocarEspacoMatrizInt(numeroVilas, numeroVilas);

    int verticeA, verticeB;
    for (int i = 0; i < numeroCaminhos; i++)
    {
        cin >> verticeA >> verticeB;
        matrizArestas[verticeA][verticeB] = 1;
        matrizArestas[verticeB][verticeA] = 1;
    }

    for (int i = 0; i < numeroVilas; i++)
    {
        for (int j = 0; j < numeroVilas; j++)
        {
            if(matrizArestas[i][j]){
                cout << i << endl;
                cout << j << endl;
                for (int k = 0; k < numeroVilas; k++)
                {
                    matrizArestas[i][k] = 0;
                    matrizArestas[k][i] = 0;
                    matrizArestas[j][k] = 0;
                    matrizArestas[k][j] = 0;
                }
            }
        }
    }
    limparEspacoMatriz(matrizArestas, numeroVilas);
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

    if(tipoTarefa == "tarefa1") execucaoTarefa1(numeroVilas, numeroCaminhos);
    else if(tipoTarefa == "tarefa2") execucaoTarefa2(numeroVilas, numeroCaminhos);
    else 
    {
        cout << "A tarefa informada é inválida. Tente novamente" << endl;
        return -1;
    }

    cin.rdbuf(cinbuf); //Reinicializando o buffer de leitura
    return 0;
}