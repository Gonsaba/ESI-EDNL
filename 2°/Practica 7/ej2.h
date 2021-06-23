#ifndef EJ2_H_
#define EJ2_H_
#include "iostream"
#include "grafoPMC.h"
#include "alg_grafo_E-S.h"
#include "alg_grafoPMC.h"
#include "alg_grafo_funciones.h"

typedef GrafoP<double>::vertice Casilla;
typedef vector<Casilla> Camino;

struct CaminoLaberinto
{
    Casilla o, d;
    Camino c;
    double l;
};

struct Pared
{
    Casilla a, b;
    Pared(Casilla aa, Casilla bb): a(aa), b(bb) {};
};

CaminoLaberinto resolverLaberinto(int N, vector<Pared> paredLaberinto, Casilla entrada, 
    Casilla salida)
{
    CaminoLaberinto resLaberinto;
    vector<double> m;
    GrafoP<double> G(N*N);

    for(int i = 0; i < N*N; ++i)
        for(int j = 0; j < N*N; ++j)
            if(i == j)
                G[i][j] = 0;
            else
                G[i][j] = GrafoP<double>::INFINITO;

    for(int i = 0; i < N*N; ++i)
    {
        if((i + 1) % N != 0)
            G[i][i + 1] = G[i + 1][i] = 1;
        if(i / N < N - 1)
            G[i][i + N] = G[i + N][i] = 1;
    }

    for (int i = 0; i < paredLaberinto.size(); ++i)
        G[paredLaberinto[i].a][paredLaberinto[i].b] = 
        G[paredLaberinto[i].b][paredLaberinto[i].a] = GrafoP<double>::INFINITO;

    m = Dijkstra(G, entrada, resLaberinto.c);

    resLaberinto.o = entrada;
    resLaberinto.d = salida;
    resLaberinto.l = m[salida];

    return resLaberinto;
}

#endif