#include <iostream>
#include "grafoPMC.h"
#include "alg_grafo_E-S.h"
#include "alg_grafoPMC.h"
#include "ej1.h"

int main(){

    int n = 4;

    vector<coordenadas> v = 
    { coordenadas(0,0),coordenadas(1,1),coordenadas(2,2),coordenadas(3,3)};

    vector<vector<bool>> vecs = {
        {true,false,false,true},
        {false,true,true,false},
        {false,true,true,true},
        {true,false,true,true}
    };

    matriz<bool> m(4);

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            m[i][j] = vecs[i][j];

    for(int i = 0; i < n; ++i)
        l.insertar(v[i],l.fin());

    distribucionTombuctu(m,v);
}