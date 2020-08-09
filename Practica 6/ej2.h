#ifndef EJ2_H_
#define EJ2_H_

#include "alg_grafoPMC.h"

template<typename tCoste>
tCoste calcDiametro(const GrafoP<tCoste> &G){
    typedef typename GrafoP<tCoste>::vertice vertice;
    matriz<vertice> c;
    vertice a, b, v, w;
    tCoste diametro = GrafoP<tCoste>::INFINITO, ca, cb;
    matriz<int> m = Floyd(G, c);

    for(v = 0; v < G.numVert(); ++v){
        ca = cb = 0;
        for(w = 0; w < G.numVert(); ++w){
            if(ca < m[v][w]){
                cb = ca;
                ca = m[v][w];
                b = a;
                a = w;
            }
            else if(cb < m[v][w]){
                cb = m[v][w];
                b = w;
            }
        }
        
        diametro = std::min(suma(ca,cb), diametro);
    }

    return diametro;
}

#endif