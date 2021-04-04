#ifndef EJ4_H_
#define EJ4_H_
#include <iostream>
#include "abb.h"
#include "colaenla.h"
#include "ej2.h"

template <typename T>
void interseccionColas(Cola<T> &elA, Cola<T> &elB, Cola<T> &elementos, int &n)
{
    while (!elA.vacia() && !elB.vacia())
    {
        if (elA.frente() == elB.frente())
        {
            elementos.push(elA.frente());
            elA.pop();
            elB.pop();
            ++n;
        }
        else if (elA.frente() < elB.frente())
            elA.pop();
        else
            elB.pop();
    }
}

template <typename T>
Abb<T> interseccionEquilibrada(Abb<T> &A, Abb<T> &B)
{
    Abb<T> C;
    Cola<T> elA, elB, elementos;
    int n = 0, n1, n2;
    inorden(A, elA, n1);
    inorden(B, elB, n2);
    interseccionColas(elA, elB, elementos, n);
    equilibrarAbbRec(C, elementos, n);
    return C;
}

#endif