#include <iostream>
#include "grafoPMC.h"
#include "alg_grafo_E-S.h"
#include "alg_grafoPMC.h"
#include "alg_grafo_funciones.h"
#include "ej2.h"
#include "ej3.h"
#include "ej4.h"

double inf = GrafoP<double>::INFINITO;

void ej5()
{
    
}

void ej4()
{
    GrafoP<double> G("zuelandiaej4.dat");
    matriz<GrafoP<double>::vertice> P;
    matriz<double> m;
    vector<Camino> caminoResistencia {Camino(1, 0)};
    vector<bool> ciudadResistencia {false, false, false, false, false, true, false};
    m = costesZuelandia(0, caminoResistencia, ciudadResistencia, G);
    printMatrix(m);
}

void ej3()
{
    GrafoP<double> G(5);
    vector<vector<double>> v = {
        {inf, 10, inf, 30, 100},
        {inf, inf, 50, inf, inf},
        {inf, inf, inf, inf, 10},
        {inf, inf, 20, inf, 60},
        {inf, inf, inf, inf, inf}};

    for (int i = 0; i < 5; i++)
        G[i] = v[i];

    std::cout << std::boolalpha << esAciclico(G) << std::endl;
}

void ej2()
{
    GrafoP<double> G(5);
    vector<vector<double>> v = {
        {inf, 10, inf, 30, 100},
        {inf, inf, 50, inf, inf},
        {inf, inf, inf, inf, 10},
        {inf, inf, 20, inf, 60},
        {inf, inf, inf, inf, inf}};

    for (int i = 0; i < 5; i++)
        G[i] = v[i];

    std::cout << diametroGrafo(G) << std::endl;
}

void ej1()
{
    std::vector<GrafoP<double>::vertice> P, PInv;
    std::vector<double> D, DInv;
    GrafoP<double> G("grafoTest.dat");

    D = Dijkstra(G, 0, P);

    for (int i = 0; i < D.size(); i++)
    {
        std::cout << D[i] << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < P.size(); i++)
    {
        int pos = i;
        while(pos != 0)
        {
            std::cout << pos << " <- ";
            pos = P[pos];
        }
        std::cout << pos << std::endl;
    }
    std::cout << std::endl;

    DInv = DijkstraInv(G, 0, PInv);

    for (int i = 0; i < DInv.size(); i++)
    {
        std::cout << DInv[i] << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < PInv.size(); i++)
    {
        int pos = i;
        while (pos != 0)
        {
            std::cout << pos << " -> ";
            pos = PInv[pos];
        }
        std::cout << pos << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    // ej1();
    // ej2();
    // ej3();
    // ej4();
    ej5();
}