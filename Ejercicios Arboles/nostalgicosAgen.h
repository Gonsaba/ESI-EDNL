#ifndef NOSTALGICOSAGEN_H_
#define NOSTALGICOSAGEN_H_

#include "agen.h"
#include "agen_E-S.h"

template <typename T>
int antecesoresNodo(typename Agen<T>::nodo n, Agen<T> A)
{
    if(n == Agen<T>::NODO_NULO)
        return -1;
    else
        return 1 + antecesoresNodo(A.padre(n), A);
}

template <typename T> 
int descendientesNodo(typename Agen<T>::nodo n, Agen<T> A)
{
    int descendientes;
    typename Agen<T>::nodo hijo;
    descendientes = 0;

    if(n == Agen<T>::NODO_NULO)
        return descendientes;
    else
    {
        hijo = A.hijoIzqdo(n);
        while(hijo != Agen<T>::NODO_NULO)
        {
            descendientes += 1 + descendientesNodo(hijo, A);
            hijo = A.hermDrcho(hijo);
        }
        return descendientes;
    } 
}

template <typename T>
int numNostalgicosRec(typename Agen<T>::nodo n, Agen<T> A)
{
    int nNostalgicos;
    typename Agen<T>::nodo hijo;
    
    nNostalgicos = 0;
    if(n == Agen<T>::NODO_NULO)
        return 0;
    else
    {
        hijo = A.hijoIzqdo(n);
        while(hijo != Agen<T>::NODO_NULO)
        {
            nNostalgicos += numNostalgicosRec(hijo, A);
            hijo = A.hermDrcho(hijo);
        }

        if(descendientesNodo(n, A) < antecesoresNodo(n, A))
            return 1 + nNostalgicos;
        else
            return nNostalgicos;
    }
    
}

template <typename T>
int numNostalgicos(Agen<T> A)
{
    if(A.arbolVacio())
        return 0;
    else
        return numNostalgicosRec(A.raiz(), A);
}

#endif