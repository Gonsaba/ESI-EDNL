#ifndef EJ2_H_
#define EJ2_H_

#include <cmath>
#include <iostream>
#include "alg_grafoPMC.h"

struct ciudad{
    double x_,y_;
    ciudad(double x = 0,double y = 0): x_(x), y_(y) {}
};

struct lineaCiudades{
    int c1,c2;
    lineaCiudades(int c1_, int c2_): c1(c1_),  c2(c2_){}
};

struct lineaAerea{
    lineaCiudades ciudades;
    int rep1,rep2;
    double distancia;
    lineaAerea(lineaCiudades c,int r1, int r2, double d): ciudades(c), rep1(r1),
    rep2(r2), distancia(d) {}
};

double distancia(ciudad a,ciudad b){
    return sqrt(pow(a.x_-b.x_,2) + pow(a.y_-b.y_,2));
}

int existeLinea(int r1,int r2, vector<lineaAerea> lineas){
    for(int i = 0; i < lineas.size(); ++i){
        if(lineas[i].rep1 == r1 && lineas[2].rep2 == r2)
            return i;
    }

    return -1;
}

vector<lineaAerea> distribucionTombuctu2(const vector<ciudad> &ciudades,const matriz<bool> &adyacencia,
matriz<double> &costes){
    int n = ciudades.size();
    Particion islas(n);
    int c1,c2;
    int r1,r2;
    int dist;
    vector<lineaAerea> lineas;

    typedef typename GrafoP<double>::vertice vertice;
    for(vertice v = 0; v < n; ++v){
        for(vertice w = 0; w < n; ++w){
            if(adyacencia[v][w] && v != w){
                c1 = islas.encontrar(v);
                c2 = islas.encontrar(w);
                if(c1 != c2)
                    islas.unir(c1,c2);
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            r1 = islas.encontrar(i);
            r2 = islas.encontrar(j);
            int linea = existeLinea(r1,r2,lineas);
            dist = distancia(ciudades[i],ciudades[j]);
            if(linea != -1){
                if(dist < lineas[linea].distancia){
                    lineas[linea].ciudades = lineaCiudades(i,j);
                    lineas[linea].distancia = dist;
                }
            }
            else{
                lineas.push_back(lineaAerea(lineaCiudades(i,j),r1,r2,dist));
            }
        }
    }

    return lineas;
}


#endif