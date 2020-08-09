#ifndef EJ3_H_
#define EJ3_H_

#include "alg_grafoPMC.h"

template<typename tCoste>
bool aciclica(const GrafoP<tCoste> G){
    bool esAciclica = true;
    typedef typename GrafoP<tCoste>::vertice vertice;
    matriz<vertice> c;
    matriz<tCoste> m = FloydAcic(G,c);
    for(int i = 0; i < m.dimension() && esAciclica; ++i)
        esAciclica = (m[i][i] == GrafoP<tCoste>::INFINITO);
    return esAciclica;
}

#endif