#ifndef EJ1_H_
#define EJ1_H_
#include "iostream"
#include "grafoPMC.h"
#include "alg_grafo_E-S.h"
#include "alg_grafoPMC.h"
#include "alg_grafo_funciones.h"

typedef GrafoP<double>::vertice Ciudad;

struct Viaje
{
    Ciudad o, d;
    double c;
};

void imprimirViaje(Viaje v)
{
    std::cout << "Origen: " << v.o << " Destino: " << v.d << " Coste: " << v.c << std::endl;
}

template <typename T>
Viaje ViajeMasCaro(GrafoP<T> G)
{
    Viaje vRes;
    vRes.c = 0;
    matriz<double> res;
    matriz<GrafoP<double>::vertice> P;

    res = Floyd(G, P);

    for (int i = 0; i < res.dimension(); i++)
        for (int j = 0; j < res.dimension(); j++)
            if(res[i][j] < 100000 && res[i][j] > vRes.c)
            {
                vRes.o = i;
                vRes.d = j;
                vRes.c = res[i][j];
            }
    return vRes;
}

#endif