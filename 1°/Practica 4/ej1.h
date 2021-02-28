#ifndef EJ1_H_
#define EJ1_H_

#include "abb.h"

template<typename T>
void poda(Abb<T> &A,T x){
    while(!A.buscar(x).izqdo().vacio())
        A.eliminar(A.buscar(x).izqdo().elemento());
    while(!A.buscar(x).drcho().vacio())
        A.eliminar(A.buscar(x).drcho().elemento());
    A.eliminar(A.buscar(x).elemento());
}

#endif