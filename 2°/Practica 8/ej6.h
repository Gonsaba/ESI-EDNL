#ifndef EJ6_H_
#define EJ6_H_
#include <iostream>
#include "alg_grafoPMC.h"
#include "alg_grafoMA.h"
#include "alg_grafo_E-S.h"
#include "listaenla.h"
#include <cmath>
//calcular matriz, calculo: coste * nkm - subvencion * ncaudal y luego arbol expansion min

GrafoP<double> redCanalesEmasajer(GrafoP<double> GDist, GrafoP<double> GCaud,
 double subvencion, double costeKm)
{
    int n = GDist.numVert();
    GrafoP<double> G(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            GDist[i][j] *= costeKm;
            GCaud[i][j] *= subvencion;
            G[i][j] = suma(GDist[i][j], - GCaud[i][j]);
            
        }

    return Kruskall(G);
}


#endif