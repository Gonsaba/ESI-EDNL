#ifndef EJ2_H_
#define EJ2_H_

#include "alg_grafoPMC.h"

template <typename T>
T  diametroGrafo(GrafoP<T> G)
{
    typedef typename GrafoP<T>::vertice vertice;
    matriz<vertice> camino;
    vertice a, b, pseudocentro, v;
    T ca, cb, diametro;
    matriz<T> m = Floyd(G, camino);

    diametro = GrafoP<T>::INFINITO;
    ca = cb = 0;

    for (pseudocentro = 0; pseudocentro < G.numVert(); ++pseudocentro)
    {
        for(v = 0; v < G.numVert(); ++v)
        {
            if(ca < m[pseudocentro][v])
            {
                cb = ca;
                ca = m[pseudocentro][v];
                b = a;
                a = v;
            }
            else
            {
                cb = m[pseudocentro][v];
                b = v;
            }
        }
        diametro = std::min(suma(ca, cb), diametro);
    }
    
    return diametro;    
}

#endif