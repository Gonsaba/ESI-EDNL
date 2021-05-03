#ifndef EJ3_H_
#define EJ3_H_

#include "alg_grafoPMC.h"

template <typename T>
bool esAciclico(GrafoP<T> G)
{
    typedef typename GrafoP<T> v;
    bool aciclico;
    matriz<vertice> camino;
    matriz<T> m = Floyd(G, camino);
    aciclico = true;

    for(v = 0; v < G.numVert() && aciclico; ++v)
        if(m[v][v] == GrafoP<T>::INFINITO)
            aciclico = false;
        
    return aciclico;
}

#endif