#include <iostream>
#include "../material/grafoPMC.h"
#include "../material/alg_grafo_E-S.h"
#include "../material/alg_grafoPMC.h"
#include "ej1.h"
#include "ej2.h"

int main(){
    int n = 3;
    
    double inf = GrafoP<double>::INFINITO;

    Lista<pared> paredes;
    pared p1,p2;

    p1.ori = 4;
    p1.des = 5;
    p2.ori = 2;
    p2.des = 5;
    paredes.insertar(p1,paredes.fin());
    paredes.insertar(p2,paredes.fin());

    Lista<casilla> l = resLaberinto(n,paredes,0,5);

    auto p = l.primera();

    while(p != l.fin()){
        std::cout<<l.elemento(p).fil<<" "<<l.elemento(p).col<<std::endl;
        p = l.siguiente(p);
    }
}
