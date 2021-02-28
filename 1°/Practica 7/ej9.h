#ifndef EJ9_H_
#define EJ9_H_

#include "../material/alg_grafoPMC.h"

template<typename tCoste>
tCoste CalcularViaje(const GrafoP<tCoste>& G1,const GrafoP<tCoste>& G2,tCoste taxi
,typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino){
    size_t n = G1.numVert();
    typedef typename GrafoP<tCoste>::vertice vertice;
    GrafoP<tCoste>::tCamino ruta;

    GrafoP<tCoste> A(n+n);
    for(vertice i = 0; i < n; ++i){
        A[i][i] = 0;
        A[i+n][i] = A[i][i+n] = taxi;
        for(vertice j = 0; j < n; ++j){
            A[i][j] = G1[i][j];
            A[n+i][n+j] = G2[i][j];
        }
    }

    vector<vertice> p1(len),p2(len);
    vector<tCoste> vec1(len),vec2(len);

    vec1 = Dijkstra(G1,origen,ver1);
    vec2 = Dijkstra(G2,origen+n,ver2);

    tCoste costemin = std::min(std::min(vec1[destino],vec1[destino+n]),
    std::min(vec2[destino],vec2[destino+1]));

    if(min = vec1[destino]){
        ruta = camino<tCoste>(origen,destino,ver1);
    }
    else if(min = vec1[destino+n]){
        ruta = camino<tCoste>(origen,destino+n,ver1);
    }
    else if(min = vec2[destino]){
        ruta = camino<tCoste>(origen+n,destino,ver2);
    }
    else if(min = vec2[destino+n]){
        ruta = camino<tCoste>(origen+n,destino+n,ver2)
    }

    while(p != ruta.fin()){
        ruta.elemento(p) = ruta.elemento(p) % n;
        p = ruta.siguiente(p);
    }

    return costemin;

}


#endif