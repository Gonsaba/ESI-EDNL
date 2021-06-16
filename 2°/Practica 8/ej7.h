#ifndef EJ7_H_
#define EJ7_H_
#include <iostream>
#include <cmath>
#include "ej1.h"
// reconstruir las islas por separado, colocar solo un puente entre ciudades costeras,
// matriz completa, y djistra

struct Puente
{
    double coste;
    Ciudad fobos, deimos;
};

double distancia(Coordenadas a, Coordenadas b)
{
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

void reconstruirIsla(GrafoP<double>& isla, vector<Coordenadas> ciudades)
{
    int n = ciudades.size();
    for (int i = 0; i < n; ++i)
    {
        isla[i][i] = 0;
        for (int j = i + 1; j < n; ++j)
            isla[i][j] = isla[j][i] = distancia(ciudades[i], ciudades[j]);
    }

    isla = Prim(isla);
}

Puente puenteCosteMinimo(vector<Coordenadas> fobos, vector<Coordenadas> deimos, vector<Ciudad> costaFobos,
     vector<Ciudad> costaDeimos)
{
    Puente puenteMin;
    puenteMin.fobos = 0;
    puenteMin.deimos = 0;
    puenteMin.coste = GrafoP<double>::INFINITO;
    for (int i = 0; i < costaFobos.size(); ++i)
        for (int j = 0; j < costaDeimos.size(); ++j)
        {
            double coste = distancia(fobos[costaFobos[i]], deimos[costaDeimos[j]]);
            if (coste < puenteMin.coste)
            {
                puenteMin.coste = coste;
                puenteMin.fobos = costaFobos[i];
                puenteMin.deimos = costaDeimos[i];
            }
            
        }

    return puenteMin;
}

double costeViajeGrecoland(vector<Coordenadas> fobos, vector<Coordenadas> deimos, 
    vector<Ciudad> costaFobos, vector<Ciudad> costaDeimos, Ciudad origen, Ciudad destino)
{
    Puente puente = puenteCosteMinimo(fobos, deimos, costaFobos, costaDeimos);
    double coste = 0;
    int n, nFobos = fobos.size(), nDeimos = deimos.size();
    n = nFobos + nDeimos;
    GrafoP<double> GFobos(nFobos);
    GrafoP<double> GDeimos(nDeimos);
    GrafoP<double> GGrecoland(n);
    vector<double> costes;
    vector<Ciudad> P;

    reconstruirIsla(GFobos, fobos);
    reconstruirIsla(GDeimos, deimos);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            if (i < nFobos && j < nFobos)
                GGrecoland[i][j] = GFobos[i][j];
            else if(i >= nFobos && j >= nFobos)
                GGrecoland[i][j] = GDeimos[i - nFobos][j - nFobos];
        }

    GGrecoland[puente.fobos][puente.deimos + nFobos] =
        GGrecoland[puente.deimos + nFobos][puente.fobos] = puente.coste;

    costes = Dijkstra(GGrecoland, origen, P);

    return costes[destino];
}

#endif