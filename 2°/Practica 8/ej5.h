#ifndef EJ5_H_
#define EJ5_H_
#include <iostream>
#include "alg_grafoPMC.h"
#include "alg_grafoMA.h"
#include "alg_grafo_E-S.h"
#include "listaenla.h"
#include <cmath>
//arbol expansion min y sumar coste caminos

const double INFINITO = 10000;

double telefoniaReteuni3(GrafoP<double> G)
{
    double coste = 0;
    int n = G.numVert();
    G = Kruskall(G);
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (G[i][j] < INFINITO)
                coste += G[i][j];

    return coste;            
}

#endif