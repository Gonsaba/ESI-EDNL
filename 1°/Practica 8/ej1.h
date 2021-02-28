#ifndef EJ1_H_
#define EJ1_H_

#include <cmath>
#include <iostream>

struct coordenadas{
    double x_,y_;
    coordenadas(double x = 0,double y = 0): x_(x), y_(y) {}
};

double distancia(coordenadas a,coordenadas b){
    return sqrt(pow(a.x_-b.x_,2) + pow(a.y_-b.y_,2));
}

Particion distribucionTombuctu(const matriz<bool> &adyacencia,vector<coordenadas> ciudades){
    GrafoP<double> G(adyacencia.dimension());
    Particion islas(adyacencia.dimension());
    double inf = GrafoP<double>::INFINITO;
    int isla1, isla2;

    for(typename GrafoP<double>::vertice v = 0; v < G.numVert(); ++v){
        for(typename GrafoP<double>::vertice w = 0; w < G.numVert(); ++w){
            if(adyacencia[v][w])
                G[v][w] = distancia(ciudades[v],ciudades[w]);
            else
                G[v][w] = inf;
        }
    }

    for(int i = 0; i < adyacencia.dimension(); ++i){
        for(int j = 0; j < adyacencia.dimension(); ++j){
            if(adyacencia[i][j] && i != j){
                isla1 = islas.encontrar(i);
                isla2 = islas.encontrar(j);
                if(isla1 != isla2)
                    islas.unir(isla1,isla2);
            }
        }
    }

    return islas;
}

#endif