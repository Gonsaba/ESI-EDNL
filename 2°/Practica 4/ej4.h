#ifndef EJ4_H_
#define EJ4_H_
#include <iostream>
#include "abb.h"
#include "colaenla.h"
#include "ej2.h"

template <typename T>
void interseccionAbb(const Abb<T> &A, const Abb<T> &B, Abb<T> &C)
{
    if(!B.vacio())
    {
        if(!A.buscar(B.elemento()).vacio())
            C.insertar(B.elemento());
        interseccionAbb(A, B.izqdo(), C);
        interseccionAbb(A, B.drcho(), C);
    }
}

template <typename T>
Abb<T> interseccionEquilibrada(Abb<T> &A, Abb<T> &B)
{
    Abb<T> C;
    interseccionAbb(A, B, C);
    if(!C.vacio())
        equilibrarAbb(C);
    return C;
}

#endif