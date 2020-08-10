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


Lista<GrafoP<int>::vertice> resLaberinto(int n,Lista<pared> &paredes,GrafoP<int>::vertice o,GrafoP<int>::vertice d){
    GrafoP<int> G(n*n);
    for(int i = 0; i < n*n; ++i)
        for(int j = 0; j < n*n; ++j)
            G[i][j] = 1;
    
    Lista<pared>::posicion p = paredes.primera();
    while(p != paredes.fin()){
        G[paredes.elemento(p).ori][paredes.elemento(p).des] = GrafoP<int>::INFINITO;
        G[paredes.elemento(p).des][paredes.elemento(p).ori] = GrafoP<int>::INFINITO;
        p = paredes.siguiente(p);
    }

    std::cout<< G << std::endl;

    matriz<GrafoP<int>::vertice> c;
    matriz<int> m = Floyd(G,c);
     
    std::cout<< m << std::endl;

    auto cam = camino<int>(o,d,c);

    Lista<int>::posicion p = cam.primera();

    Lista<casilla> listaCasillas;

    while(p != cam.fin()){
        casilla c;
        c = nodoaCasilla(cam.elemento(p),n);
        listaCasillas.insertar(c,listaCasillas.fin());
    }

    return listaCasillas;
}

#endif