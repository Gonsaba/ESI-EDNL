#ifndef EJ4_H_
#define EJ4_H_
#include "iostream"
#include "grafoPMC.h"
#include "alg_grafo_E-S.h"
#include "alg_grafoPMC.h"
#include "alg_grafo_funciones.h"

double kilometrosRecorridos(GrafoP<double> G, vector<int> parte, int capital)
{
    vector<double> ida, vuelta;
    vector<GrafoP<double>::vertice> P;
    double kmRecorridos = 0;

    ida = Dijkstra(G, capital, P);
    vuelta = DijkstraInv(G, capital, P);
    
    for (int i = 0; i < G.numVert(); ++i)
        if(i != capital && parte[i] > 0)
            kmRecorridos += (ida[i] + vuelta[i]) * parte[i];

    return kmRecorridos;    
}

#endif