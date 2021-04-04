#ifndef EJ5_H_
#define EJ5_H_
#include <iostream>
#include "abb.h"
#include "ej2.h"
#include "ej3.h"
#include "ej4.h"

template <typename T>
Abb<T> operator|(Abb<T> &A,Abb<T> &B)
{
    return unionEquilibrada(A, B);
}

template <typename T>
Abb<T> operator&(Abb<T> &A, Abb<T> &B)
{
    return interseccionEquilibrada(A, B);
}

template <typename T>
Abb<T> operator-(Abb<T> &A, Abb<T> &B)
{
    Cola<T> elementos, elA, elB;
    int na, nb, n = 0;
    inorden(A, elA, na);
    inorden(B, elB, nb);
    while(!elA.vacia() || !elB.vacia())
    {
        if(elA.frente() == elB.frente())
        {
            elA.pop();
            elB.pop();
        }

    }
}

template <typename T>
Abb<T> operator*(Abb<T> &A, Abb<T> &B)
{
    return interseccionEquilibrada(A, B);
}

#endif