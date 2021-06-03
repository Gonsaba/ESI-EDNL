#include <iostream>
#include "grafoPMC.h"
#include "alg_grafo_E-S.h"
#include "alg_grafoPMC.h"
#include "alg_grafo_funciones.h"
#include "ej1.h"
#include "ej2.h"

double inf = GrafoP<double>::INFINITO;

void ej1() 
{
    GrafoP<double> G("grafoej1.dat");
    matriz<GrafoP<double>::vertice> P;

    Viaje viaje = ViajeMasCaro(G);
    imprimirViaje(viaje);
}

void ej2()
{
    vector<Pared> paredLaberinto{ Pared(1, 4), Pared(3, 4), Pared(4, 5)};
    CaminoLaberinto caminoLaberinto = resolverLaberinto(3, paredLaberinto, 0, 5);
    vector<Casilla> P = caminoLaberinto.c; 
    int pos = caminoLaberinto.d;
    while (pos != caminoLaberinto.o)
    {
        std::cout << pos << " <- ";
        pos = P[pos];
    }
    std::cout << pos << std::endl;
}

int main()
{
    // ej1();
    ej2();
}