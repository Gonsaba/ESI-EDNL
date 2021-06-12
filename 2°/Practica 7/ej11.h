#ifndef EJ11_H_
#define EJ11_H_
#include "iostream"
#include "grafoPMC.h"
#include "alg_grafo_E-S.h"
#include "alg_grafoPMC.h"
#include "alg_grafo_funciones.h"

typedef GrafoP<double>::vertice Ciudad;
typedef int Isla;

struct Puente
{
    Ciudad a, b;
    Isla ia, ib;
    Puente (Ciudad a_, Ciudad b_, Isla ia_, Isla ib_) : a(a_), b(b_), ia(ia_), ib(ib_) {};
};

Ciudad islaAZuelandia(Ciudad ciudad, Isla isla, int n1, int n2, int n3)
{
    Ciudad res;
    switch (isla)
    {
    case 0:
        res = ciudad;
        break;
    case 1:
        res = ciudad + n1;
        break;
    case 2:
        res = ciudad + n1 + n2;
        break;
    
    default:
        res = -1;
        break;
    }

    return res;
}

matriz<double> costesMinimosZuelandia(GrafoP<double> isla1, GrafoP<double> isla2, 
                                      GrafoP<double> isla3, vector<Puente> puente)
{
    int n1, n2, n3, ciudad1, ciudad2;
    n1 = isla1.numVert();
    n2 = isla2.numVert();
    n3 = isla3.numVert();
    GrafoP<double> G(n1 + n2 + n3);
    matriz<Ciudad> P;

    for (int i = 0; i < n1 + n2 + n3; ++i)
        for (int j = 0; j < n1 + n2 + n3; ++j)
            G[i][j] = GrafoP<double>::INFINITO;

    for (int i = 0; i < n1 + n2 + n3; ++i)
        for (int j = 0; j < n1 + n2 + n3; ++j)
        {
            if(i < n1 && j < n1)
                G[i][j] = isla1[i][j];
            else if (i < n1 + n2 && j < n1 + n2 && i > n1 - 1 && j > n1 - 1)
                G[i][j] = isla2[i - n1][j - n1];
            else if (i < n1 + n2 + n3 && j < n1 + n2 + n3 && i > n1 + n2 - 1 &&
                j > n1 + n2 - 1)
                G[i][j] = isla3[i - n1 - n2][j - n1 - n2];
        }

    for (int i = 0; i < puente.size(); ++i)
    {
        ciudad1 = islaAZuelandia(puente[i].a, puente[i].ia, n1, n2, n3);
        ciudad2 = islaAZuelandia(puente[i].b, puente[i].ib, n1, n2, n3);
        G[ciudad1][ciudad2] = G[ciudad2][ciudad1] = 0;
    }

    return Floyd(G, P);
}

#endif