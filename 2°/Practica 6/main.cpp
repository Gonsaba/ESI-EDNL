#include <iostream>
#include "grafoPMC.h"
#include "alg_grafo_E-S.h"
#include "alg_grafoPMC.h"
#include "ej2.h"
#include "ej3.h"

void ej3()
{
    
}

void ej2()
{
    GrafoP<double> G(5);

    double inf = GrafoP<double>::INFINITO;
    vector<vector<double>> v = {
        {0, inf, inf, inf, 8},
        {inf, 0, 1, inf, 2},
        {inf, 3, 0, inf, inf},
        {inf, inf, 1, 0, inf},
        {8, inf, 7, 3, 0}};

    for (int i = 0; i < 5; i++)
        G[i] = v[i];

    std::cout << diametroGrafo(G) << std::endl;
}

int main()
{
    ej2();
}