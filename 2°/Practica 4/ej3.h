#ifndef EJ3_H_
#define EJ3_H_
#include <iostream>
#include "abb.h"
#include "colaenla.h"
#include "ej2.h"

template <typename T>
void unionAbb(Abb<T> &A,const Abb<T> &B)
{
    if(!B.vacio())
    {
        A.insertar(B.elemento());
        unionAbb(A, B.izqdo());
        unionAbb(A, B.drcho());
    }
}

template <typename T>
Abb<T> unionEquilibrada(Abb<T> &A, Abb<T> &B)
{
    Abb<T> C = A;
    Cola<T> elA, elB, elementos;
    int n = 0, n1, n2;
    unionAbb(C, B);
    equilibrarAbb(C);
    return C;
}

#endif