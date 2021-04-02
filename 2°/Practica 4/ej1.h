#ifndef EJ1_H_
#define EJ1_H_
#include "abb.h"

template <typename T>
void eliminarSubarbol(Abb<T>& A, T a)
{
    while(!A.buscar(a).izqdo().vacio())
        A.eliminar(A.buscar(a).izqdo().elemento());

    while (!A.buscar(a).drcho().vacio())
        A.eliminar(A.buscar(a).drcho().elemento());
    
    A.eliminar(a);
}

template <typename T>
void eliminarSubarbolRec(Abb<T> &A, T a)
{
    if (!A.buscar(a).izqdo().vacio())
        eliminarSubarbolRec(A, A.buscar(a).izqdo().elemento());

    if (!A.buscar(a).drcho().vacio())
        eliminarSubarbolRec(A, A.buscar(a).drcho().elemento());

    A.eliminar(a);
}

#endif