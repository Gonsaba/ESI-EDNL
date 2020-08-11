#ifndef EJ2_H_
#define EJ2_H_

#include <iostream>
#include "../material/alg_grafoPMC.h"

struct pared{
    int ori,des;
};

struct casilla{
    int fil,col;
};

casilla nodoaCasilla(int nod, int n){
    casilla c;
    c.fil = nod/n;
    c.col = nod%n;
    return c;
}

int casillaaNodo(casilla c, int n){
    return (c.fil * n) + c.col;
}

bool adyacente(casilla i,casilla j){
    return ((abs(i.col - j.col) + abs(i.fil - j.fil)) == 1);
}

Lista<casilla> resLaberinto(int n,Lista<pared> &paredes,GrafoP<int>::vertice o,GrafoP<int>::vertice d){
    GrafoP<int> G(n*n);
    int inf = GrafoP<int>::INFINITO;
    for(int i = 0; i < n*n; ++i)
        for(int j = i; j < n*n; ++j){
            if(i==j){
                G[i][j] = 0;
            }
            else if(adyacente(nodoaCasilla(i,n),nodoaCasilla(j,n))){
                G[i][j] = 1;
                G[j][i] = 1;
            }
            else{
                G[i][j] = inf;
                G[j][i] = inf;
            }
        }
    
    Lista<pared>::posicion itp = paredes.primera();
    while(itp != paredes.fin()){
        G[paredes.elemento(itp).ori][paredes.elemento(itp).des] = GrafoP<int>::INFINITO;
        G[paredes.elemento(itp).des][paredes.elemento(itp).ori] = GrafoP<int>::INFINITO;
        itp = paredes.siguiente(itp);
    }

    matriz<GrafoP<int>::vertice> c;
    matriz<int> m = Floyd(G,c);

    Lista<GrafoP<int>::vertice> l = camino<GrafoP<int>::vertice>(o,d,c);

    Lista<casilla> listaCasillas;


    auto pos = l.primera();
    while(pos != l.fin()){
        listaCasillas.insertar(nodoaCasilla(l.elemento(pos),n),listaCasillas.fin());
        pos = l.siguiente(pos);
    }

    return listaCasillas;
}

#endif