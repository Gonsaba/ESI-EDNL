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
            else if (i < n * 3 && j < n * 3)
                GBusTrenAvion[i][j] = avion[i % n][j % n];
            else GBusTrenAvion[i][j] = GrafoP<T>::INFINITO;
        }

    printGrafo(GBusTrenAvion);
    
    return viajeMin;
}

#endif