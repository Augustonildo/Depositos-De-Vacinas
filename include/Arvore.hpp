#include "Vila.hpp"

class Arvore
{
public:
    Arvore();
    Arvore(Vila* raiz, int numeroVilas);
    Vila* getRaiz();
    int getCoberturaMinimaDeVilas();

private:
    Vila* raiz;
    int coberturaMinimaDeVilas; 
    int numeroVilas;
    void encontraCoberturaMinimaPorDfs(Vila* vila, Vila* vilaMae, int* vilasCobertas, int* vilasSelecionadas);
};