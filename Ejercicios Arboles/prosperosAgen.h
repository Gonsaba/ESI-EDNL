#ifndef PROSPEROSAGEN_H_
#define PROSPEROSAGEN_H_

#include "agen.h"

template <typename T>
bool antecesores(typename Agen<T>::nodo n, T e, Agen<T> A)
{
    if(n == Agen<T>::NODO_NULO)
        return true;
    else
    {
        if(e < A.elemento(n))
            return false;
        else
            return antecesores(A.padre(n), e, A);
    }
    
}

template <typename T>
bool descendientes(typename Agen<T>::nodo n, T e, Agen<T> A)
{
    bool prospero;
    typename Agen<T>::nodo hijo;

    if(n == Agen<T>::NODO_NULO)
        return true;
    else
    {
        prospero = true;
        hijo = A.hijoIzqdo(n);
        if(A.elemento(n) < e)
            prospero = false;
        else
            while (hijo != Agen<T>::NODO_NULO && prospero)
            {
                prospero = descendientes(hijo, e, A);
                hijo = A.hermDrcho(hijo);
            }
        return prospero;
    }
}

template <typename T>
bool prospero(typename Agen<T>::nodo n, Agen<T> A)
{
    bool prospero;
    typename Agen<T>::nodo hijo;

    if(antecesores(A.padre(n), A.elemento(n), A))
    {
        prospero = true;
        hijo = A.hijoIzqdo(n);
        while (hijo != Agen<T>::NODO_NULO && prospero)
        {
            prospero = descendientes(hijo, A.elemento(n), A);
            hijo = A.hermDrcho(hijo);
        }
        return prospero;
    }
    else
        return false;
}

template <typename T>
int numProsperosRec(typename Agen<T>::nodo n, Agen<T> A)
{
    int nProsperos;
    typename Agen<T>::nodo hijo;
    
    if(n == Agen<T>::NODO_NULO)
        return 0;
    else
    {
        nProsperos = 0;
        hijo = A.hijoIzqdo(n);
        while (hijo != Agen<T>::NODO_NULO)
        {
            nProsperos += numProsperosRec(hijo, A);
            hijo = A.hermDrcho(hijo);
        }
        if(prospero(n, A))
            return 1 + nProsperos;
        else
            return nProsperos;
    }
    
}

template <typename T>
int numProsperos(Agen<T> A)
{
    if(A.arbolVacio())
        return 0;
    else
        return numProsperosRec(A.raiz(), A);
}

#endif