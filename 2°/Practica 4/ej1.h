#ifndef EJ1_H_
#define EJ1_H_
#include "abb.h"

template <typename T>
void eliminarSubArbol(Abb<T>& A, T a)
{
    while(!A.buscar(a).izqdo().vacio())
        A.eliminar(A.buscar(a).izqdo().elemento());
}

#endif