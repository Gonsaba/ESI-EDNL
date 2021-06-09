#ifndef EJ9_H_
#define EJ9_H_
#include "iostream"
#include "grafoPMC.h"
#include "alg_grafo_E-S.h"
#include "alg_grafoPMC.h"
#include "alg_grafo_funciones.h"

typedef GrafoP<double>::vertice Vertice;

struct ViajeEj9 {
    double coste;
    vector<Vertice> camino1, camino2;
};

template <typename T>
ViajeEj9 costeMin(GrafoP<T> bus, GrafoP<T> tren, int origen, int destino,
                  T costeTaxi)
{
    ViajeEj9 viajeMin;
    int n = bus.numVert();
    GrafoP<T> GBusTren(n * 2);
    vector<T> costes1, costes2;
    vector<Vertice> P1, P2;
    matriz<Vertice> Pborrar;

    for (int i = 0; i < n * 2; ++i)
        for (int j = 0; j < n * 2; ++j)
            if (i < n && j < n)
                GBusTren[i][j] = bus[i][j];
            else if(i > n && j > n)
                GBusTren[i][j] = tren[i % n][j % n];
            else if(i < n)
                GBusTren[i][j] = tren[i][j % n] + costeTaxi;
            else
                GBusTren[i][j] = bus[i % n][j] + costeTaxi;

    printGrafo(GBusTren);

    costes1 = Dijkstra(GBusTren, origen, P1);
    costes2 = Dijkstra(GBusTren, origen + n, P2);

    viajeMin.coste = costes1[destino];
    if (costes1[destino + n] < viajeMin.coste)
        viajeMin.coste = costes1[destino + n];
    if (costes2[destino] < viajeMin.coste)
        viajeMin.coste = costes2[destino];
    if (costes2[destino + n] < viajeMin.coste)
        viajeMin.coste = costes2[destino + n];

    viajeMin.camino1 = P1;
    viajeMin.camino2 = P2;

    std::cout << costes1[destino] << std::endl;
    std::cout << costes1[destino + n] << std::endl;
    std::cout << costes2[destino] << std::endl;
    std::cout << costes2[destino + n] << std::endl;

    return viajeMin;
}

#endif