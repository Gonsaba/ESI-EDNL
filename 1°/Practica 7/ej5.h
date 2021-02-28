#ifndef EJ5_H_
#define EJ5_H_

#include "../material/alg_grafoPMC.h"
#include<string>

vector<int> ciudadesVisitables(double disponible,GrafoP<double> a,GrafoP<double> b,GrafoP<double> c, int origen,int alergia){
    
    int n = 3;

    double inf = GrafoP<double>::INFINITO;
    vector<GrafoP<double>::vertice> p;
    vector<vector<double>> transportesCostes(3);
    vector<int> destinos;

    std::cout<<a<<std::endl;

    transportesCostes[0] = Dijkstra(a,origen,p);
    transportesCostes[1] = Dijkstra(b,origen,p);
    transportesCostes[2] = Dijkstra(c,origen,p);

    for(int j = 0; j < transportesCostes.size(); ++j){
        for(int i = 0; i < transportesCostes[j].size(); ++i){
            std::cout<<transportesCostes[j][i]<<" ";
        }
        std::cout<<std::endl;
    }

    for(int i = 0; i < n; ++i){
        int transporte = -1;
        double coste = inf;
        for(int j = 0; j < transportesCostes.size(); ++j){
            if(j != alergia && transportesCostes[j][i] != inf && transportesCostes[j][i] < coste){
                coste = transportesCostes[j][i];
            }
        }

        if(coste != inf && coste < disponible){
            destinos.push_back(i);
        }
    }
    
    return destinos;
}

#endif