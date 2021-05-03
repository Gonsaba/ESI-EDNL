#ifndef NOSTALGICOSABIN_H_
#define NOSTALGICOSABIN_H_

#include "abin.h"
#include "abin_E-S.h"

template <typename T>
int antecesoresNodo(typename Abin<T>::nodo n, Abin<T> A)
{
    if(n == Abin<T>::NODO_NULO)
        return -1;
    else
        return 1 + antecesoresNodo(A.padre(n), A);
}

template <typename T>
int descendientesNodoRec(typename Abin<T>::nodo n, Abin<T> A)
{
    if (n == Abin<T>::NODO_NULO)
        return 0;
    else
        return 1 + descendientesNodoRec(A.hijoIzqdo(n), A)
            + descendientesNodoRec(A.hijoDrcho(n), A);
}

template <typename T>
int descendientesNodo(typename Abin<T>::nodo n, Abin<T> A)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        return descendientesNodoRec(A.hijoIzqdo(n), A)
            + descendientesNodoRec(A.hijoDrcho(n), A);
}

template <typename T>
int numNostalgicosRec(typename Abin<T>::nodo n, Abin<T> A)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
    {
        if (descendientesNodo(n, A) < antecesoresNodo(n, A))
            return 1 + numNostalgicosRec(A.hijoIzqdo(n), A)
                + numNostalgicosRec(A.hijoDrcho(n), A);
        else
            return numNostalgicosRec(A.hijoIzqdo(n), A)
                + numNostalgicosRec(A.hijoDrcho(n), A);
    }
}

template <typename T>
int numNostalgicos(Abin<T> A)
{
    if(!A.arbolVacio())
        return numNostalgicosRec(A.raiz(), A);
    else 
        return 0;
}

#endif