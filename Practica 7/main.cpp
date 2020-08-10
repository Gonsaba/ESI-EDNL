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
    pared p;

    for(int i = 0; i < n*n; ++i)
        for(int j = i; j < n*n; ++j)
            if(i != j+1 && i != j && i != j-1){
                p.ori = i;
                p.des = j;
                if(i != 3 || j != 5)
                    paredes.insertar(p,paredes.fin());  
            }

    Lista<unsigned int> l = resLaberinto(n,paredes,0,5);

    Lista<unsigned int>::posicion pos = l.primera();
    while(pos != l.fin()){
        std::cout<<l.elemento(pos);
        pos = pos->sig;
    }
}
