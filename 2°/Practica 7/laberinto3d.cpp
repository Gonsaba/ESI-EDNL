#ifndef LABERINTO3D_H_
#define LABERINTO3D_H_
#include <iostream>
#include <cmath>
#include "grafoPMC.h"
#include "alg_grafo_E-S.h"
#include "alg_grafoPMC.h"
#include "alg_grafo_funciones.h"

typedef GrafoP<double>::vertice Casilla;

const double INFINITO = GrafoP<double>::INFINITO;

struct Pared
{
    int casilla1, casilla2;
    Pared(int c1, int c2) : casilla1(c1), casilla2(c2) {};
};

struct Coordenada3D
{
    int x, y, z;
    Coordenada3D(int _x = -1, int _y = -1, int _z = -1) : x(_x), y(_y), z(_z) {};
};

void imprimirCoordenada(Coordenada3D c)
{
    std::cout << "x: " << c.x << " y: " << c.y << " z: " << c.z << std::endl;
}

Casilla coordenadaCasilla(Coordenada3D cord, int n)
{
    return cord.x + cord.y * n + cord.z * std::pow(n, 2);
}

Coordenada3D casillaCoordenada(Casilla c, int n)
{
    int r, x, y, z;
    int n2 = std::pow(n, 2);
    z = c / n2;
    r = c % n2;
    y = r / n;
    x = r % n;

    return Coordenada3D(x, y, z);
}

vector<Casilla> resolverLaberinto3D(int n, vector<Pared> paredes, int entrada, int salida)
{
    Coordenada3D cActual;
    int tam = std::pow(n, 3);
    GrafoP<double> G(tam);
    vector<double> costes;
    vector<Casilla> P;

    for (Casilla i = 0; i < tam; ++i)
    {
        cActual = casillaCoordenada(i, n);
        if (cActual.x + 1 < n)
        {
            G[i][coordenadaCasilla(Coordenada3D(cActual.x + 1, cActual.y, cActual.z), n)] =
                G[coordenadaCasilla(Coordenada3D(cActual.x + 1, cActual.y, cActual.z), n)][i] = 
                1;
        }
        if (cActual.y + 1 < n)
        {
            G[i][coordenadaCasilla(Coordenada3D(cActual.x, cActual.y + 1, cActual.z), n)] =
                G[coordenadaCasilla(Coordenada3D(cActual.x, cActual.y + 1, cActual.z), n)][i] = 
                1;
        }
        if (cActual.z + 1 < n)
        {
            G[i][coordenadaCasilla(Coordenada3D(cActual.x, cActual.y, cActual.z + 1), n)] =
                G[coordenadaCasilla(Coordenada3D(cActual.x, cActual.y, cActual.z + 1), n)][i] = 
                1;
        }
    }

    for (int i = 0; i < paredes.size(); ++i)
    {
        G[paredes[i].casilla1][paredes[i].casilla2] =
            G[paredes[i].casilla2][paredes[i].casilla1] = INFINITO;
    }
    costes = Dijkstra(G, entrada, P);
    return P;
}

int main()
{
    int entrada = 0;
    int salida = 26;
    vector<Pared> paredes{Pared(0, 1), Pared(25, 26), Pared(0, 9)};
    vector<Casilla> P = resolverLaberinto3D(3, paredes, entrada, salida);

    int pos = salida;
    while (pos != entrada)
    {
        std::cout << pos << " <- ";
        pos = P[pos];
    }
    std::cout << pos << std::endl;
}

#endif