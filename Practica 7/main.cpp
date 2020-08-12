#include <iostream>
#include "../material/grafoPMC.h"
#include "../material/alg_grafo_E-S.h"
#include "../material/alg_grafoPMC.h"
#include "ej3.h"

int main(){    
    GrafoP<double> G(5);
    double inf = GrafoP<double>::INFINITO;
    vector<vector<double>> v = {
        {0, 5, inf, inf, 8},
        {inf, 0, 1, inf, 2},
        {inf, 3, 0, inf, 3},
        {8, inf, 1, 0, inf},
        {8, inf, 7, 3, 0}
    };

    for(int i = 0; i < G.numVert(); ++i)
        G[i] = v[i];

    vector<int> capacidades = {20,70,50,200,100};
    
    vector<double> porcentajes = {20,10,50,30,25};

    vector<int> enviarCiudades = calcCamino(3,200,G,capacidades,porcentajes);

    for(int i = 0; i < enviarCiudades.size(); ++i){
        std::cout<< "Ciudad "<<i<<" Cantidad "<<enviarCiudades[i]<<std::endl;
    }
}
