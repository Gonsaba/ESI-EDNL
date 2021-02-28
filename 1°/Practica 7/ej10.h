#ifndef EJ10_H_
#define EJ10_H_
#include "../material/alg_grafoPMC.h"

template<typename tCoste>
typename GrafoP<tCoste>::tCamino calcularCamino(typename GrafoP<tCoste>::vertice origen,
typename GrafoP<tCoste>::vertice destino, size_t n,vector<tCoste> vec,
vector<typename GrafoP<tCoste>::vertice> path,tCoste coste){

    typename GrafoP<tCoste>::tCamino ruta;

    if(vec[destino] < vec[n+destino]){
        if(vec[destino] < vec[2*n+destino])
            ruta = camino<tCoste>(origen,destino,path);
        else
            ruta = camino<tCoste>(origen,2*n+destino,path);
    }
    else if(vec[n+destino] < vec[2*n+destino])
        ruta = camino<tCoste>(origen,n+destino,path);
    else
        ruta = camino<tCoste>(origen,2*n+destino,path);

    return ruta;
}

template<typename tCoste>
tCoste calcularCosteViaje(GrafoP<tCoste> G1,GrafoP<tCoste> G2,GrafoP<tCoste> G3,
typename GrafoP<tCoste>::vertice origen,typename GrafoP<tCoste>::vertice destino,
tCoste taxi1,tCoste taxi2,typename GrafoP<tCoste>::tCamino &camino){
    typedef typename GrafoP<tCoste>::vertice vertice;
    size_t n = G1.numVert();
    size_t len = 3*n;
    tCoste coste;
    vector<tCoste> vec1,vec2,vec3;
    vector<vertice> p1,p2,p3;

    GrafoP<tCoste> A(len);
    for(int i = 0; i < n; ++i){
        A[n+i][i] = A[i][n+i] = taxi1;
        A[2*n+i][i] = A[i][2*n+i] = taxi2; 
        for(int j = 0; j < n; ++j){
            A[i][j] = G1[i][j];
            A[n+i][n+j] = G2[i][j];
            A[2*n+i][2*n+j] = G3[i][j];
        }
    }

    vec1 = Dijkstra(G1,origen,p1);
    vec2 = Dijkstra(G2,n+origen,p2);
    vec3 = Dijkstra(G3,2*n+origen,p3);

    tCoste costemin1 = std::min(std::min(vec1[destino],vec1[n+destino]),vec1[2*n+destino]);
    tCoste costemin2 = std::min(std::min(vec2[destino],vec2[n+destino]),vec2[2*n+destino]);
    tCoste costemin3 = std::min(std::min(vec3[destino],vec3[n+destino]),vec3[2*n+destino]);
    
    coste = std::min(costemin1,std::min(costemin2,costemin3));

    if(coste == costemin1)
        camino = calcularCamino(origen,destino,n,vec1,p1,costemin1);
    else if(coste == costemin2)
        camino = calcularCamino(n+origen,destino,n,vec2,p2,costemin2);
    else
        camino = calcularCamino(2*n+origen,destino,n,vec3,p3,costemin3);

    return coste;

}


#endif