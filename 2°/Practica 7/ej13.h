#ifndef EJ13_H_
#define EJ13_H_
#include "iostream"
#include "grafoPMC.h"
#include "alg_grafo_E-S.h"
#include "alg_grafoPMC.h"
#include "alg_grafo_funciones.h"

typedef GrafoP<double>::vertice Ciudad;

struct PuenteEj13
{
    Ciudad c1, c2;
    int isla1, isla2;
    PuenteEj13(Ciudad c1_, Ciudad c2_, int i1, int i2) : c1(c1_), c2(c2_),
        isla1(i1), isla2(i2){};
};

struct CosteCiudad
{
    Ciudad ciudad;
    double coste;
    CosteCiudad(Ciudad ciu, double cos) : ciudad(ciu), coste(cos) {};
};

double costeMedioEj13(matriz<double> costes, Ciudad ciudad)
{
    int n = costes.dimension();
    double coste = costes[ciudad][ciudad];

    for (int i = 0; i < n; ++i)
        if (ciudad != i)
            coste += costes[ciudad][i] + costes[i][ciudad];

    return coste / ((n * 2) - 1);
}

CosteCiudad costeMedioMinEj13(matriz<double> costes,
                              vector<Ciudad> ciudadCostera)
{
    double costeMin = costeMedioEj13(costes, ciudadCostera[0]), coste;
    Ciudad ciudadMin = ciudadCostera[0];
    for (int i = 1; i < ciudadCostera.size(); ++i)
    {
        coste = costeMedioEj13(costes, ciudadCostera[i]);
        if (coste < costeMin)
        {
            costeMin = coste;
            ciudadMin = ciudadCostera[i];
        }
    }

    return CosteCiudad(ciudadMin, costeMin);
}

vector<PuenteEj13> puentesHuries(GrafoP<double> G1, GrafoP<double> G2,
                          GrafoP<double> G3,
                           vector<Ciudad> costa1, vector<Ciudad> costa2,
                           vector<Ciudad> costa3)
{
    matriz<double> m1, m2, m3;
    matriz<Ciudad> P;
    vector<PuenteEj13> puentes;

    m1 = Floyd(G1, P);
    m2 = Floyd(G2, P);
    m3 = Floyd(G3, P);

    CosteCiudad ciudadMin1 = costeMedioMinEj13(m1, costa1);
    CosteCiudad ciudadMin2 = costeMedioMinEj13(m2, costa2);
    CosteCiudad ciudadMin3 = costeMedioMinEj13(m3, costa3);

    if (ciudadMin1.coste < ciudadMin2.coste && 
        ciudadMin1.coste < ciudadMin3.coste)
        puentes = { PuenteEj13(ciudadMin1.ciudad, ciudadMin2.ciudad, 0, 1),
                    PuenteEj13(ciudadMin1.ciudad, ciudadMin3.ciudad, 0, 2)};
    else if(ciudadMin2.coste < ciudadMin3.coste)
        puentes = {PuenteEj13(ciudadMin2.ciudad, ciudadMin1.ciudad, 1, 0),
                   PuenteEj13(ciudadMin2.ciudad, ciudadMin3.ciudad, 1, 2)};
    else
        puentes = {PuenteEj13(ciudadMin3.ciudad, ciudadMin2.ciudad, 2, 1),
                   PuenteEj13(ciudadMin3.ciudad, ciudadMin1.ciudad, 2, 0)};
        
    return puentes;
}

#endif