#include <iostream>
#include "../material/grafoPMC.h"
#include "../material/alg_grafo_E-S.h"
#include "../material/alg_grafoPMC.h"
#include "ej3.h"
#include "ej4.h"
#include "ej5.h"

int main(){    
    GrafoP<double> G1(4);
    GrafoP<double> G2(4);
    GrafoP<double> G3(4);
    double inf = GrafoP<double>::INFINITO;

    vector<vector<double>> v1 = {
        {0, inf, 5, 5},
        {0, inf, 5, 5},
        {0, inf, 5, 5},
        {0, inf, 5, 5}
    };

    vector<vector<double>> v2 = {
        {0, inf, 5, 5},
        {0, inf, 5, 5},
        {0, inf, 5, 5},
        {0, inf, 5, 5}
    };

    vector<vector<double>> v3 = {
        {0, 5, 5, inf},
        {0, 5, 5, 5},
        {0, 5, 5, 5},
        {0, 5, 5, 5}
    };

    for(int i = 0; i < G1.numVert(); ++i)
        G1[i] = v1[i];

    for(int i = 0; i < G2.numVert(); ++i)
        G2[i] = v2[i];

    for(int i = 0; i < G3.numVert(); ++i)
        G3[i] = v2[i];

    vector<int> l = ciudadesVisitables((double)200,G1,G2,G3,0,2);

    for(int i = 0; i < l.size(); ++i){
        std::cout<<l[i]<<" ";
    }
}

