#include <iostream>
#include "grafoPMC.h"
#include "alg_grafo_E-S.h"
#include "alg_grafoPMC.h"
#include "ej2.h"
#include "ej3.h"

int main(){
    GrafoP<int> G(3);
    
    int inf = GrafoP<int>::INFINITO;
    vector<vector<int>> vec = {
        {0,4,inf},
        {5,0,17},
        {6,inf,0}
    };

    for(int i = 0; i < 3; i++)
        G[i] = vec[i];

    std::cout<<std::boolalpha<<aciclica(G)<<std::endl;
}