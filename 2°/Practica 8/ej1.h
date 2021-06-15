#ifndef EJ1_H_
#define EJ1_H_
#include <iostream>
#include "alg_grafoPMC.h"
#include "alg_grafoMA.h"
#include "alg_grafo_E-S.h"
#include "listaenla.h"
#include "particion.cpp"
#include <cmath>
//Se puede hacer con warshall

//particion: si adyacencia(i,j) && p.encontrar(i) != p.encontra(j) 
//  -> p.unir(p.encontrar(i), p.encontrar(j))

//distancias minimas: matriz adyacencia y distancias entre islas con floyd

struct Coordenadas
{
    double x, y;
    Coordenadas(double x_, double y_) : x(x_), y(y_) {};
};

struct TombuctuEj1
{
    Particion p;
    matriz<double> coste;
    TombuctuEj1(Particion p_, matriz<double> coste_) : p(p_), coste(coste_) {};
};

TombuctuEj1 archipielagoTombuctu(vector<Coordenadas> ciudades, Grafo GA)
{
    int n = GA.numVert();
    GrafoP<double> G(n);
    matriz<GrafoP<double>::vertice> P;
    Particion p(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (GA[i][j])
            {
                G[i][j] = std::sqrt(std::pow(ciudades[i].x - ciudades[j].x, 2) + 
                                    std::pow(ciudades[i].y - ciudades[j].y, 2));
                if (p.encontrar(i) != p.encontrar(j))
                    p.unir(p.encontrar(i), p.encontrar(j));
            }

    return TombuctuEj1(p, Floyd(G, P));
}

#endif