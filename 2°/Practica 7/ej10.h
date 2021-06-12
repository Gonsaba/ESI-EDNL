#ifndef EJ10_H_
#define EJ10_H_
#include "iostream"
#include "grafoPMC.h"
#include "alg_grafo_E-S.h"
#include "alg_grafoPMC.h"
#include "alg_grafo_funciones.h"

typedef GrafoP<double>::vertice Vertice;

struct ViajeEj10
{
    double coste;
    vector<Vertice> camino1, camino2, camino3;
};

template <typename T>
ViajeEj10 viajeCosteMinimo(GrafoP<T> bus, GrafoP<T> tren, GrafoP<T> avion,
    int origen, int destino, double costeTaxiBusTren, double costeTaxiAvion)
{
    ViajeEj10 viajeMin;
    int n = bus.numVert();
    GrafoP<T> GBusTrenAvion(n * 3);
    vector<T> costes1, costes2, costes3;
    vector<Vertice> P1, P2, P3;

    for (int i = 0; i < n * 3; ++i)
        for (int j = 0; j < n * 3; ++j)
        {
            if(i < n && j < n)
                GBusTrenAvion[i][j] = bus[i % n][j % n];
            else if(i < n && j < n * 2)
                GBusTrenAvion[i][j] = tren[i % n][j % n] + 
                                        costeTaxiBusTren;
            else if (i < n && j < n * 3)
                GBusTrenAvion[i][j] = avion[i % n][j % n] + 
                                        costeTaxiAvion;
            else if (i < n * 2 && j < n)
                GBusTrenAvion[i][j] = bus[i % n][j % n] + 
                                        costeTaxiBusTren;
            else if (i < n * 2 && j < n * 2)
                GBusTrenAvion[i][j] = tren[i % n][j % n];
            else if(i < n * 2 && j < n * 3)
                GBusTrenAvion[i][j] = avion[i % n][j % n] +
                                        costeTaxiAvion;
            else if (i < n * 3 && j < n)
                GBusTrenAvion[i][j] = bus[i % n][j % n] +
                                        costeTaxiAvion;
            else if (i < n * 3 && j < n * 2)
                GBusTrenAvion[i][j] = tren[i % n][j % n] +
                                        costeTaxiAvion;
            else
                GBusTrenAvion[i][j] = avion[i % n][j % n];
        }

    // printGrafo(GBusTrenAvion);

    costes1 = Dijkstra(GBusTrenAvion, origen, P1);
    costes2 = Dijkstra(GBusTrenAvion, origen + n, P2);
    costes3 = Dijkstra(GBusTrenAvion, origen + (n * 2), P3);

    viajeMin.coste = costes1[destino];
    if (costes1[destino + n] < viajeMin.coste)
        viajeMin.coste = costes1[destino + n];
    if (costes1[destino + (n * 2)] < viajeMin.coste)
        viajeMin.coste = costes1[destino + (n * 2)];

    if (costes2[destino] < viajeMin.coste)
        viajeMin.coste = costes2[destino];
    if (costes2[destino + n] < viajeMin.coste)
        viajeMin.coste = costes2[destino + n];
    if (costes2[destino + (n * 2)] < viajeMin.coste)
        viajeMin.coste = costes2[destino + (n * 2)];

    if (costes3[destino] < viajeMin.coste)
        viajeMin.coste = costes3[destino];
    if (costes3[destino + n] < viajeMin.coste)
        viajeMin.coste = costes3[destino + n];
    if (costes3[destino + (n * 2)] < viajeMin.coste)
        viajeMin.coste = costes3[destino + (n * 2)];

    viajeMin.camino1 = P1;
    viajeMin.camino2 = P2;
    viajeMin.camino3 = P3;

    // std::cout << costes1[destino] << std::endl;
    // std::cout << costes1[destino + n] << std::endl;
    // std::cout << costes1[destino + (n * 2)] << std::endl;

    // std::cout << costes2[destino] << std::endl;
    // std::cout << costes2[destino + n] << std::endl;
    // std::cout << costes2[destino + (n * 2)] << std::endl;

    // std::cout << costes3[destino] << std::endl;
    // std::cout << costes3[destino + n] << std::endl;
    // std::cout << costes3[destino + (n * 2)] << std::endl;

    return viajeMin;
}

#endif