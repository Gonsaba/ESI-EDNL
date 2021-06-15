#ifndef EJ2_H_
#define EJ2_H_
#include <iostream>
#include "ej1.h"
#include <cmath>
// Devolver resultado de matriz de islas x islas,
// Sacar numero de islas durante creacion de particion, islas = ciudades,
//  cuando unir --islas
// Con nislas guardar representantes hasta nencontrados == nislas || 
//  recorridas todas las ciudades
// Para todo i j si encontrar(i) != encontrar(j), 
//  A = posisla de encontrar(i),
// B = posisla de encontrar(i), si dist entre i y j 
//  es mas pequeña que entre A y B, almacenar
// Matriz costes minimos

typedef Grafo::vertice Ciudad;

struct LineaAerea
{
    Ciudad a, b;
    Ciudad capA, capB;
    double coste;
    LineaAerea(){};
    LineaAerea(Ciudad a_, Ciudad b_, Ciudad capA_, Ciudad capB_, double coste_) : 
        a(a_), b(b_), capA(capA_), capB(capB_), coste(coste_) {};
};

void insertarLinea(LineaAerea lineaAerea, vector<LineaAerea>& lineasAereas)
{
    bool existeLinea = false;
    for (int i = 0; i < lineasAereas.size() && !existeLinea; ++i)
        if ((lineaAerea.capA == lineasAereas[i].capA && lineaAerea.capB == lineasAereas[i].capB)
            || (lineaAerea.capA == lineasAereas[i].capB &&
                 lineaAerea.capB == lineasAereas[i].capA))
        {
            existeLinea = true;
            if (lineaAerea.coste < lineasAereas[i].coste)
                lineasAereas[i] = lineaAerea;
        }
    
    if (!existeLinea)
        lineasAereas.push_back(lineaAerea);
}

vector<LineaAerea> lineasAereasTombuctu(Grafo GA, vector<Coordenadas> ciudad)
{
    int n = GA.numVert();
    int nIslas = n;
    Particion p(n);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (GA[i][j] && p.encontrar(i) != p.encontrar(j))
            {
                --nIslas;
                p.unir(p.encontrar(i), p.encontrar(j));
            }
    
    vector<LineaAerea> lineasAereas;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            int capA = p.encontrar(i), capB = p.encontrar(j);
            if (capA != capB)
            {
                double coste = std::sqrt(
                    std::pow(ciudad[i].x - ciudad[j].x, 2) + 
                    std::pow(ciudad[i].y - ciudad[j].y, 2));

                insertarLinea(LineaAerea(i, j, capA, capB, coste), lineasAereas);
            }
        }
    
    return lineasAereas;
}


#endif