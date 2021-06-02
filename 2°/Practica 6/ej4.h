#ifndef EJ4_H_
#define EJ4_H_

#include "alg_grafoPMC.h"

typedef GrafoP<double>::vertice Ciudad;

struct Camino
{
    Ciudad o;
    Ciudad d;
    Camino(Ciudad origen, Ciudad destino) : o(origen), d(destino){};
};

template <typename T>
matriz<T> costesZuelandia(Ciudad capital, vector<Camino> &caminoResistencia,
                          vector<bool> &ciudadResistencia, GrafoP<T> G)
{
    matriz<T> costes(G.numVert());
    vector<T> dijkstra, dijkstraInv;
    matriz<Ciudad> mP;
    vector<Ciudad> vP;
    Ciudad v, w;

    for (int i = 0; i < ciudadResistencia.size(); ++i)
        if (ciudadResistencia[i])
            for (v = 0; v < G.numVert(); ++v)
                G[i][v] = G[v][i] = GrafoP<T>::INFINITO;

    for(int i = 0; i < caminoResistencia.size(); ++i)
        G[caminoResistencia[i].o][caminoResistencia[i].d] = GrafoP<T>::INFINITO;

    dijkstra = Dijkstra(G, capital, vP);
    dijkstraInv = DijkstraInv(G, capital, vP);

    for (int i = 0; i < G.numVert(); i++)
        for (int j = 0; j < G.numVert(); j++)
            costes[i][j] = dijkstraInv[i] + dijkstra[j];

    return costes;
}

#endif