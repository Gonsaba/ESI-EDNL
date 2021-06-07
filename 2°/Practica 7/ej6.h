#ifndef EJ6_H_
#define EJ6_H_
#include "iostream"
#include "grafoPMC.h"
#include "alg_grafo_E-S.h"
#include "alg_grafoPMC.h"
#include "alg_grafo_funciones.h"

typedef GrafoP<double>::vertice vertice;


template <typename T>
matriz<T> costesMinimos(GrafoP<T> bus, GrafoP<T> tren,int ciudadTrasbordo)
{
    int n = bus.numVert();
    matriz<vertice> P;
    GrafoP<T> trasbordoBusTren(n), trasbordoTrenBus(n);
    matriz<T> costeBus, costeTren, costeTrasbordoBusTren, costeTrasbordoTrenBus, res;

    res = matriz<T>(n);
    trasbordoBusTren = bus;
    trasbordoTrenBus = tren;

    trasbordoBusTren[ciudadTrasbordo] = tren[ciudadTrasbordo];
    trasbordoTrenBus[ciudadTrasbordo] = bus[ciudadTrasbordo];

    costeBus = Floyd(bus, P);
    costeTren = Floyd(tren, P);
    costeTrasbordoBusTren = Floyd(trasbordoBusTren, P);
    costeTrasbordoTrenBus = Floyd(trasbordoTrenBus, P);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            res[i][j] = std::min(costeBus[i][j], std::min(costeTren[i][j],
             std::min(trasbordoBusTren[i][j], trasbordoTrenBus[i][j])));

    return res;
}

#endif