#ifndef EJ3_H_
#define EJ3_H_
#include "agenLis.h"
#include <iostream>

template <typename T>
int altura(Agen<T> A, typename Agen<T>::nodo n)
{
    typename Agen<T>::nodo hijo;
    int altMax = 0, alt = 0;

    hijo = A.hijoIzqdo(n);
    while (hijo != Agen<T>::NODO_NULO)
    {
        alt = 1 + altura(A, hijo);
        if (altMax < alt)
            altMax = alt;
        hijo = A.hermDrcho(hijo);
    }
    return alt;
    
}

template <typename T>
int desequilibrioRec(Agen<T> A, typename Agen<T>::nodo n)
{
    typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
    int max, min, alt, deseq, deseqMax;
    if(hijo != Agen<T>::NODO_NULO)
    {
        max = 1 + altura(A, hijo);
        min = max;
        deseqMax = desequilibrioRec(A, hijo);
        hijo = A.hermDrcho(hijo);
        while (hijo != Agen<T>::NODO_NULO)
        {
            alt =  1 + altura(A, hijo);
            if(max < alt)
                max = alt;
            if(alt < min)
                min = alt;

            deseq = desequilibrioRec(A, hijo);
            if (deseqMax < deseq)
                deseqMax = deseq;

            hijo = A.hermDrcho(hijo);
        }
        return std::max(deseqMax, max - min);
    }
}

template <typename T>
int desequilibrio(Agen<T> A)
{
    return desequilibrioRec(A, A.raiz());
}

#endif