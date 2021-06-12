#ifndef EJ12_H_
#define EJ12_H_
#include "iostream"
#include "grafoPMC.h"
#include "alg_grafo_E-S.h"
#include "alg_grafoPMC.h"
#include "alg_grafo_funciones.h"

typedef GrafoP<double>::vertice Ciudad;

enum islaej12 {FOBOSEJ12, DEIMOSEJ12};

struct PuenteEj12
{
    Ciudad c1, c2;
    int isla1, isla2;
    PuenteEj12(Ciudad c1_, Ciudad c2_, int i1, int i2) : c1(c1_), c2(c2_),
                                                         isla1(i1), isla2(i2){};
};

double costeMedio(matriz<double> costes, Ciudad ciudad)
{
    int n = costes.dimension();
    double coste = costes[ciudad][ciudad];

    for (int i = 0; i < n; ++i)
        if(ciudad != i)
            coste += costes[ciudad][i] + costes[i][ciudad];
    
    return coste / ((n * 2) - 1);
}

double costeMedioMin(matriz<double> costes, vector<Ciudad> ciudadCostera)
{
    double costeMin = costeMedio(costes, ciudadCostera[0]), coste;
    Ciudad ciudadMin = ciudadCostera[0];
    for (int i = 1; i < ciudadCostera.size(); ++i)
    {
        coste = costeMedio(costes, ciudadCostera[i]);
        if (coste < costeMin)   
        {
            costeMin = coste;
            ciudadMin = ciudadCostera[i];
        }
    }

    return ciudadMin;
}

PuenteEj12 puenteZuelandia(GrafoP<double> GFobos, GrafoP<double> GDeimos,
                           vector<Ciudad> costFobos, vector<Ciudad> costDeimos)
{
    matriz<double> mFobos, mDeimos;
    matriz<Ciudad> PFobos, PDeimos;
    Ciudad ciuFobos, ciuDeimos;
    double coste;

    mFobos = Floyd(GFobos, PFobos);
    mDeimos = Floyd(GDeimos, PDeimos);
    
    ciuFobos = costeMedioMin(mFobos, costFobos);
    ciuDeimos = costeMedioMin(mDeimos, costDeimos);

    return PuenteEj12(ciuFobos, ciuDeimos, FOBOSEJ12, DEIMOSEJ12);
}

#endif