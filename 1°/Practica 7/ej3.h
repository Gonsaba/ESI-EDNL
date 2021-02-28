#ifndef EJ3_H_
#define EJ3_H_

#include <iostream>
#include "../material/alg_grafoPMC.h"

template<typename tCoste>
vector<int> calcCamino(int o, int nprod, GrafoP<tCoste> G,const vector<int> &capacidades,const vector<double> &porcentajes){
    typedef typename GrafoP<tCoste>::vertice vertice;
    int n = G.numVert();

    for(vertice v = 0; v < n; ++v)
        for(vertice w = 0; w < n; ++w)
            if(G[v][w] != GrafoP<tCoste>::INFINITO)
                G[v][w] = G[v][w] * (1 - (porcentajes[w]/100));

    vector<vertice> p;
    vector<tCoste> costes = Dijkstra(G,o,p);

    for(int i = 0; i < costes.size(); ++i)   
        std::cout<< costes[i] << std::endl;

    vector<int> enviar(n,0);

    while(nprod > 0){
        tCoste min = GrafoP<tCoste>::INFINITO;
        int ciudad = o;
        for(int i = 0; i < n; ++i){
            if(i != o && enviar[i] == 0 && costes[i] < min){
                min = costes[i];
                ciudad = i;
            }
        }

        if(capacidades[ciudad] < nprod){
            enviar[ciudad] = capacidades[ciudad];
            nprod -= capacidades[ciudad];
        }
        else{
            enviar[ciudad] = nprod;
            nprod = 0;
        }
    }

    return enviar;
}

#endif