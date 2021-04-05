#ifndef EJ1_H_
#define EJ1_H_
#include "abb.h"

//V1
template <typename T>
void eliminarSubarbol(Abb<T>& A, T a)
{
    while(!A.buscar(a).izqdo().vacio())
        A.eliminar(A.buscar(a).izqdo().elemento());

    while (!A.buscar(a).drcho().vacio())
        A.eliminar(A.buscar(a).drcho().elemento());
    
    A.eliminar(a);
}

//V2
template <typename T>
void eliminarSubarbolRec(Abb<T> &A, T a)
{
    if (!A.buscar(a).izqdo().vacio())
        eliminarSubarbolRec(A, A.buscar(a).izqdo().elemento());

    if (!A.buscar(a).drcho().vacio())
        eliminarSubarbolRec(A, A.buscar(a).drcho().elemento());

    A.eliminar(a);
}

//eliminar con destructor
template <typename T>
void eliminarSubarbolV3(Abb<T> &A, T a)
{
    A.buscar(a).~Abb();
}

#endif