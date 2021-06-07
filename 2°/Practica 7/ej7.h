#ifndef EJ7_H_
#define EJ7_H_
#include "iostream"
#include "grafoPMC.h"
#include "alg_grafo_E-S.h"
#include "alg_grafoPMC.h"
#include "alg_grafo_funciones.h"

typedef GrafoP<double>::vertice Vertice;

struct viajeDosTrasbordos
{
    double coste;
    vector<Vertice> camino;
};

template <typename T>
viajeDosTrasbordos viajeCosteMinimo(int origen, int destino, int cambio1, int cambio 2,
    GrafoP<T> tren, GrafoP<T> bus)
{
    
}

#endif