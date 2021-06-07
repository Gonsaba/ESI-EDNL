#ifndef EJ5_H_
#define EJ5_H_
#include "iostream"
#include "grafoPMC.h"
#include "alg_grafo_E-S.h"
#include "alg_grafoPMC.h"
#include "alg_grafo_funciones.h"

enum {CARRETERA, TREN, AVION};

vector<bool> ciudadesViajablesCalc(GrafoP<double> medio1, GrafoP<double> medio2, int alergia,
                                   double dinero, int salida)
{
    vector<double> coste;
    vector<GrafoP<double>::vertice> P;
    int n = medio1.numVert();
    vector<bool> puedeViajar(n, false);

    GrafoP<double> G = medio1;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            G[i][j] = std::min(G[i][j], medio2[i][j]);

    coste = Dijkstra(G, salida, P);
    for (int i = 0; i < n; ++i)
        if (i != salida && coste[i] <= dinero)
            puedeViajar[i] = true;

    return puedeViajar;
}

vector<bool> ciudadesViajables(GrafoP<double> carretera, GrafoP<double> tren,
                                 GrafoP<double> avion, int alergia, double dinero,
                                 int salida)
{
    int n = carretera.numVert();
    vector<bool> puedeViajar(n, false);
    switch (alergia)
    {
    case CARRETERA:
        puedeViajar = ciudadesViajablesCalc(tren, avion, alergia, dinero, salida);
        break;
    case TREN:
        puedeViajar = ciudadesViajablesCalc(carretera, avion, alergia, dinero, salida);
        break;
    case AVION:
        puedeViajar = ciudadesViajablesCalc(tren, carretera, alergia, dinero, salida);
        break;
    default:
        break;
    }

    return puedeViajar;
}

#endif