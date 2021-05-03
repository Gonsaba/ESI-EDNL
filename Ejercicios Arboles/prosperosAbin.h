#ifndef PROSPEROSABIN_H_
#define PROSPEROSABIN_H_

#include "abin.h"

template <typename T>
bool antecesores(typename Abin<T>::nodo n, T e, Abin<T> A)
{
    if(n == Abin<T>::NODO_NULO)
        return true;
    else
    {
        if(A.elemento(n) <= e)
            return antecesores(A.padre(n), e, A);
        else
            return false;
    }
}

template <typename T>
bool descendientes(typename Abin<T>::nodo n, T e, Abin<T> A)
{
    if(n == Abin<T>::NODO_NULO)
        return true;
    else
    {
        if(e <= A.elemento(n))
            return descendientes(A.hijoIzqdo(n), e, A) && 
                descendientes(A.hijoIzqdo(n), e, A);
        else
            return false;
    }
}

template <typename T>
bool prospero(typename Abin<T>::nodo n, Abin<T> A)
{
    return antecesores(A.padre(n), A.elemento(n), A) 
        && descendientes(A.hijoIzqdo(n), A.elemento(n), A)
        && descendientes(A.hijoDrcho(n), A.elemento(n), A);
}

template <typename T>
int numProsperosRec(typename Abin<T>::nodo n, Abin<T> A)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
    {
        if(prospero(n, A))
            return 1 + numProsperosRec(A.hijoIzqdo(n), A)
                + numProsperosRec(A.hijoDrcho(n), A);
        else
            return numProsperosRec(A.hijoIzqdo(n), A)
                + numProsperosRec(A.hijoDrcho(n), A);
    }
    
}

template <typename T>
int numProsperos(Abin<T> A)
{
    if(A.arbolVacio())
        return 0;
    else
        return numProsperosRec(A.raiz(), A);
}

#endif