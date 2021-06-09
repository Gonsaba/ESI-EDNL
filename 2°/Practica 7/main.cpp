#include <iostream>
#include "grafoPMC.h"
#include "alg_grafo_E-S.h"
#include "alg_grafoPMC.h"
#include "alg_grafo_funciones.h"
#include "ej1.h"
#include "ej2.h"
#include "ej3.h"
#include "ej4.h"
#include "ej5.h"
#include "ej6.h"
#include "ej7.h"
#include "ej8.h"
#include "ej9.h"

typedef GrafoP<double>::vertice Vertice;
typedef vector<Vertice> Camino;
typedef matriz<Vertice> Caminos;
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

void ej3()
{
    matriz<GrafoP<double>::vertice> P;
    GrafoP<double> G("grafoej3.dat");
    vector<int> capacidadCiudad = {0, 10, 50, 70, 80, 15, 35};
    vector<double> subvencionCiudad = {0, 50, 25, 10, 15, 20, 35};
    PlanReparto planReparto;

    planReparto = calcularReparto(0, 200, G, capacidadCiudad, subvencionCiudad);

    std::cout << "Coste: " << planReparto.coste << std::endl;
    for (int i = 0; i < planReparto.cargaCiudad.size(); ++i)
        std::cout << "Ciudad: " << i << " Carga: " << planReparto.cargaCiudad[i] << std::endl;
}

void ej4()
{
    GrafoP<double> G("grafoej4.dat");
    vector<int> parte = {0, 10, 0, 15, 2, 12, 7};

    std::cout << "Km: " << kilometrosRecorridos(G, parte, 0) << std::endl;
}

void ej5()
{
    vector<bool> puedeViajar;
    Caminos P;
    GrafoP<double> carretera("grafoej5carretera.dat");
    GrafoP<double> tren("grafoej5tren.dat");
    GrafoP<double> avion("grafoej5avion.dat");

    printMatrix(Floyd(carretera, P));
    std::cout << std::endl;
    printMatrix(Floyd(tren, P));
    std::cout << std::endl;
    printMatrix(Floyd(avion, P));
    std::cout << std::endl;

    puedeViajar = ciudadesViajables(carretera, tren, avion, 1, 100, 0);

    for (int i = 0; i < carretera.numVert(); ++i)
        if(puedeViajar[i])
            std::cout << "Puede viajar a la ciudad " << i << std::endl;
}

void ej6()
{
    GrafoP<double> bus("grafoej5carretera.dat");
    GrafoP<double> tren("grafoej5tren.dat");
    matriz<double> costesMinimosTransporte = costesMinimos(bus, tren, 0);

    printMatrix(costesMinimosTransporte);
}

void ej7()
{
    GrafoP<double> bus("grafoej7bus.dat");
    GrafoP<double> tren("grafoej7tren.dat");
    ViajeDosTrasbordos viaje = viajeCosteMinimo(0, 5, 4, 6, tren, bus);

    std::cout << viaje.coste << std::endl;
    printVector(viaje.camino);
}

void ej8()
{
    GrafoP<double> bus("grafoej8bus.dat");
    GrafoP<double> tren("grafoej7tren.dat");
    vector<bool> puedeTrasbordo{
        false,
        false,
        false,
        false,
        true,
        false,
        true
    };

    ViajeEj8 viaje = costesMinimos(bus, tren, puedeTrasbordo, 0, 5);

    std::cout << "Coste: " << viaje.coste << std::endl;
    std::cout << "Medio Inicial: " << viaje.medioInicial << std::endl;
    std::cout << "Trasbordo: " << viaje.ciudadTrasbordo << std::endl;
}

void ej9()
{
    ViajeEj9 viaje;
    GrafoP<double> bus ("grafoej9bus.dat"), tren("grafoej9tren.dat");
    viaje = costeMin(bus, tren, 0, 5,(double) 15);
    std::cout << "Coste: " << viaje.coste << std::endl;
    printVector(viaje.camino1);
    printVector(viaje.camino2);
}

int main()
{
    // ej1();
    // ej2();
    // ej3();
    // ej4();
    // ej5();
    // ej6();
    // ej7();
    // ej8();
    ej9();
}