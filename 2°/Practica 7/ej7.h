#ifndef EJ7_H_
#define EJ7_H_
#include "iostream"
#include "grafoPMC.h"
#include "alg_grafo_E-S.h"
#include "alg_grafoPMC.h"
#include "alg_grafo_funciones.h"

typedef GrafoP<double>::vertice Vertice;

struct ViajeDosTrasbordos
{
    double coste;
    vector<Vertice> camino;
};

template <typename T>
ViajeDosTrasbordos viajeCosteMinimo(int origen, int destino, int cambio1,
    int cambio2, GrafoP<T> tren, GrafoP<T> bus)
{
    int pos;
    ViajeDosTrasbordos viajeDosTrasbordos;
    vector<vertice> camino1, camino2, aux;
    double coste1, coste2;

    coste1 = Dijkstra(bus, cambio1, camino1)[destino] +
             DijkstraInv(tren, cambio1, aux)[origen];
    pos = origen;
    while(pos != cambio1)
    {
        camino1[aux[pos]] = pos;
        pos = aux[pos];
    }

    coste2 = Dijkstra(bus, cambio2, camino2)[destino] +
             DijkstraInv(tren, cambio2, aux)[origen];
    pos = origen;
    while (pos != cambio2)
    {
        camino1[aux[pos]] = pos;
        pos = aux[pos];
    }

    if (coste1 < coste2)
    {
        viajeDosTrasbordos.camino = camino1;
        viajeDosTrasbordos.coste = coste1;
    }
    else
    {
        viajeDosTrasbordos.camino = camino2;
        viajeDosTrasbordos.coste = coste2;
    }
    
    

    return viajeDosTrasbordos;
}

#endif