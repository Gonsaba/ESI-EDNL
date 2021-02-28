#ifndef EJ4_H_
#define EJ4_H_

#include "../material/alg_grafoPMC.h"

struct parte
{
    int destino;
    int cargas;
};


vector<double> calckmCamiones(GrafoP<double> G,vector<parte> destinoCamion,GrafoP<double>::vertice capital){
    typedef typename GrafoP<double>::vertice vertice;
    int n = G.numVert();
    matriz<vertice> p;
    vector<double> costesDestinoCamion(destinoCamion.size());

    matriz<double> costes = Floyd(G,p);

    for(int i = 0; i < destinoCamion.size();++i)
        while(destinoCamion[i].cargas > 0){
            costesDestinoCamion[i] = costes[capital][destinoCamion[i].destino];
            destinoCamion[i].cargas--;
        }

    return costesDestinoCamion;
}

#endif