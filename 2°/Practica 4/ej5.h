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
    Abb<T> C;
    Cola<T> elementos, elA, elB;
    int na, nb, n = 0;
    inorden(A, elA, na);
    inorden(B, elB, nb);
    while(!elA.vacia())
    {
        if (!elB.vacia()) 
        {
            if(elA.frente() == elB.frente())
            {
                elA.pop();
                elB.pop();
            }
            else if(elA.frente() < elB.frente())
            {
                elementos.push(elA.frente());
                ++n;
                elA.pop();
            }
            else
                elB.pop();
        }
        else
        {
            elementos.push(elA.frente());
            ++n;
            elA.pop();
        }
    }
    equilibrarAbbRec(C, elementos, n);
    return C;
}

template <typename T>
void insertarNoComunes(const Abb<T> &A, const Abb<T> &B, Abb<T> &C)
{
    if(!A.vacio())
    {
        if(B.buscar(A.elemento()).vacio())
            C.insertar(A.elemento());
        insertarNoComunes(A.izqdo(), B, C);
        insertarNoComunes(A.drcho(), B, C);
    }
}

template <typename T>
Abb<T> operator*(Abb<T> &A, Abb<T> &B)
{
    Abb<T> C;
    insertarNoComunes(A, B, C);
    insertarNoComunes(B, A, C);
    // imprimirAbb(C);
    // equilibrarAbb(C);
    return C;
}

#endif