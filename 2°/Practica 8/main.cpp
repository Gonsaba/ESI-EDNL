#include <iostream>
#include "alg_grafoPMC.h"
#include "grafoMA.h"
#include "particion.h"
#include "alg_grafo_funciones.h"
#include "ej1.h"
#include "ej2.h"
#include "ej3.h"
#include "ej4.h"
#include "ej5.h"
#include "ej6.h"
#include "ej7.h"
#include "apoMax.h"

void grafoPToGrafo(GrafoP<double>& GP, Grafo& G)
{
    for (int i = 0; i < GP.numVert(); ++i)
        for (int j = 0; j < GP.numVert(); ++j)
            if (!GP[i][j])
                G[i][j] = true;
            else
                G[i][j] = false;
}

void ej1()
{
    vector<Coordenadas> ciudades{Coordenadas(2, 2), Coordenadas(4, 4), 
                                    Coordenadas(6, 6), Coordenadas(8, 8),
                                    Coordenadas(10, 10)};
    Grafo G(5);
    GrafoP<double> GP("grafoMAEj1.dat");
    grafoPToGrafo(GP, G);
    TombuctuEj1 res = archipielagoTombuctu(ciudades, G);

    printParticion(res.p, GP.numVert());
    printMatrix(res.coste);
}

void ej2()
{
    vector<Coordenadas> ciudades{Coordenadas(2, 2), Coordenadas(4, 4),
                                 Coordenadas(6, 6), Coordenadas(8, 8),
                                 Coordenadas(10, 10), Coordenadas(12, 12),
                                 Coordenadas(14, 14)};
    
    Grafo G(7);
    GrafoP<double> GP("grafoMAEj2.dat");
    grafoPToGrafo(GP, G);
    vector<LineaAerea> lineasAereas = lineasAereasTombuctu(G, ciudades);

    for (int i = 0; i < lineasAereas.size(); i++)
    {
        std::cout << "Linea Aerea" << std::endl;
        std::cout << "Ciudad: " << lineasAereas[i].a << " Capital: " << 
            lineasAereas[i].capA << std::endl;
        std::cout << "Ciudad: " << lineasAereas[i].b << " Capital: " << 
            lineasAereas[i].capB << std::endl;
        std::cout << "Coste: " << lineasAereas[i].coste << std::endl;
        std::cout << std::endl;
    }
    

}

void ej3()
{
    testApoMax();    
}

void ej4()
{
    GrafoP<double> G("grafoej4.dat");
    printGrafo(G);
    std::cout << GrafoP<double>::INFINITO << std::endl;
    printGrafo(canalesEmasajer(G));
}

void ej5()
{

}

void ej6()
{

}

void ej7()
{

}

int main()
{
    // ej1();
    // ej2();
    // ej3();
    ej4();
    // ej5();
    // ej6();
    // ej7();
}