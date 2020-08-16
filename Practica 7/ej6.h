#ifndef EJ6_H_
#define EJ6_H_

#include "../material/alg_grafoPMC.h"
#include<string>

template<typename tCoste>
matriz<tCoste> mejorItinerario(GrafoP<tCoste> B,GrafoP<tCoste> T){

    matriz<GrafoP<tCoste>::vertice> p;
    matriz<tCoste> res = Floyd(B,p);
    matriz<tCoste> aux = Floyd(T,p);

    for(int i = 0; i < B.numVert(); ++i)
        for(int j = 0; j < B.numVert(); ++j){
            if(aux[i][j] < res[i][j])
                res[i][j] = aux[i][j];
        }

    

    return res;
}


#endif