#ifndef EJ3_H_
#define EJ3_H_

#include <iostream>
#include "alg_grafoPMC.h"

template <typename T>
bool esAciclico(GrafoP<T> G)
{
    typedef typename GrafoP<T>::vertice vertice;
    bool aciclico;
    vertice v, w;
    matriz<vertice> camino;
    matriz<T> m = Floyd(G, camino);
    aciclico = true;

    for (v = 0; v < G.numVert(); ++v)
        std::cout << v << " - " << v << " = " << m[v][v] << std::endl;

    for(v = 0; v < G.numVert() && aciclico; ++v)
        if(m[v][v] != GrafoP<T>::INFINITO)
            aciclico = false;
        
    return aciclico;
}

#endif