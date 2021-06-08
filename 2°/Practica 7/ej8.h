#ifndef EJ8_H_
#define EJ8_H_
#include "iostream"
#include "grafoPMC.h"
#include "alg_grafo_E-S.h"
#include "alg_grafoPMC.h"
#include "alg_grafo_funciones.h"

typedef GrafoP<double>::vertice vertice;

enum medio {EJ8BUS, EJ8TREN};

struct ViajeEj8{
    double coste;
    int medioInicial;
    int ciudadTrasbordo;
};

template <typename T>
ViajeEj8 costesMinimos(GrafoP<T> bus, GrafoP<T> tren, vector<bool> puedeTrasbordo, int origen, int destino)
{
    ViajeEj8 viajeMin;
    int n = bus.numVert();
    vector<vertice> P;
    vector<T> costeTren, costeBus;
    T costeBusTren, costeTrenBus;

    viajeMin.coste = GrafoP<T>::INFINITO;
    viajeMin.medioInicial = -1;
    viajeMin.ciudadTrasbordo = -1;

    costeBus = Dijkstra(bus, origen, P);
    costeTren = Dijkstra(tren, origen, P);

    printVector(costeBus);
    printVector(costeTren);

    if (costeBus[destino] < costeTren[destino])
    {
        viajeMin.coste = costeBus[destino];
        viajeMin.medioInicial = EJ8BUS;
    }
    else
    {
        viajeMin.coste = costeTren[destino];
        viajeMin.medioInicial = EJ8TREN;
    }

    for (int ciudad = 0; ciudad < puedeTrasbordo.size(); ++ciudad)
    {
        if (ciudad != origen && ciudad != destino
            && puedeTrasbordo[ciudad])
        {
            costeBusTren = Dijkstra(bus, origen, P)[ciudad] +
                        Dijkstra(tren, ciudad, P)[destino];
            costeTrenBus = Dijkstra(tren, origen, P)[ciudad] +
                        Dijkstra(bus, ciudad, P)[destino];

            if (costeBusTren < viajeMin.coste)
            {
                viajeMin.coste = costeBusTren;
                viajeMin.medioInicial = EJ8BUS;
                viajeMin.ciudadTrasbordo = ciudad;
            }
            if (costeTrenBus < viajeMin.coste)
            {
                viajeMin.coste = costeTrenBus;
                viajeMin.medioInicial = EJ8TREN;
                viajeMin.ciudadTrasbordo = ciudad;
            }
        }
    }

    return viajeMin;
}

#endif