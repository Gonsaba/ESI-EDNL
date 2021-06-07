#ifndef EJ3_H_
#define EJ3_H_
#include "iostream"
#include "grafoPMC.h"
#include "alg_grafo_E-S.h"
#include "alg_grafoPMC.h"
#include "alg_grafo_funciones.h"

typedef GrafoP<double>::vertice nodo;

struct PlanReparto
{
    vector<int> cargaCiudad;
    double coste;
};

template <typename T>
PlanReparto calcularReparto(nodo origen, int productos, GrafoP<T> G, 
    vector<int> capacidadCiudad, vector<double> subvencionCiudad)
{
    PlanReparto planReparto;
    vector<double> coste, costeUnProducto(G.numVert());
    vector<nodo> P;
    vector<bool> ciudadVisitada(G.numVert(), false);
    double ciudadMin, costeMin;

    planReparto.cargaCiudad = vector<int>(G.numVert(), 0);
    planReparto.coste = 0;

    coste = Dijkstra(G, origen, P);

    for (int i = 0; i < G.numVert(); ++i)
        if(i != origen)
        {
            coste[i] = coste[i] * (1 - (subvencionCiudad[i] / 100));
            costeUnProducto[i] = coste[i] / capacidadCiudad[i];
        }

    ciudadVisitada[origen] = true;
    int i = 0;
    while(i < G.numVert() - 1 && productos > 0)
    {
        costeMin = GrafoP<double>::INFINITO;
        for (int i = 0; i < G.numVert(); ++i)
            if (!ciudadVisitada[i] && costeUnProducto[i] < costeMin)
            {
                ciudadMin = i;
                costeMin = costeUnProducto[i];
            }
        
        ciudadVisitada[ciudadMin] = true;
        planReparto.coste += coste[ciudadMin];
        if (capacidadCiudad[ciudadMin] < productos)
        {
            planReparto.cargaCiudad[ciudadMin] = capacidadCiudad[ciudadMin];
            productos -= capacidadCiudad[ciudadMin];
        }
        else
        {
            planReparto.cargaCiudad[ciudadMin] = productos;
            productos = 0;
        }
        ++i;
    }

    return planReparto;
}

#endif