#ifndef EJ4_H_
#define EJ4_H_

#include "alg_grafoPMC.h"

typedef struct
{
    GrafoP<double>::vertice cA;
    GrafoP<double>::vertice cB;
} caminos;

matriz<double> costeZuelandia(GrafoP<double> G,vector<bool> ciudadesR,vector<caminos> caminoR, GrafoP<double>::vertice cap){
    matriz<double> costes;
    matriz<GrafoP<double>::vertice> c;
    
    for(int i = 0; i < ciudadesR.size(); ++i){
        if(ciudadesR[i])
            for(int j = 0; j < G.numVert(); ++j)
                G[j][i] = G[i][j] = GrafoP<double>::INFINITO;
    }

    for(int i = 0; i < caminoR.size(); ++i){
        G[caminoR[i].cA][caminoR[i].cB] = G[caminoR[i].cB][caminoR[i].cA] = GrafoP<double>::INFINITO;
    }

    costes = Floyd(G,c);

    for(GrafoP<double>::vertice v = 0; v < G.numVert(); ++v){
        for(GrafoP<double>::vertice w = 0; w < G.numVert(); ++w){
            if(v != w)
                costes[v][w] = suma(costes[v][cap],costes[cap][w]);
        }
    }

    return costes;
}

#endif