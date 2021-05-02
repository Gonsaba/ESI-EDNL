#ifndef EJ3_H_
#define EJ3_H_
#include "agen.h"
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
int altMin(Agen<T> A, typename Agen<T>::nodo n)
{
    typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
    int min, alt;
    if (hijo != Agen<T>::NODO_NULO)
    {
        min = 1 + altura(A, hijo);
        hijo = A.hermDrcho(hijo);
        while (hijo != Agen<T>::NODO_NULO)
        {
            alt = 1 + altura(A, hijo);
            if (alt < min)
                min = alt;

            hijo = A.hermDrcho(hijo);
        }
        return min;
    }
}

template <typename T>
int altMax(Agen<T> A, typename Agen<T>::nodo n)
{
    typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
    int max, alt;
    if (hijo != Agen<T>::NODO_NULO)
    {
        max = 1 + altura(A, hijo);
        hijo = A.hermDrcho(hijo);
        while (hijo != Agen<T>::NODO_NULO)
        {
            alt = 1 + altura(A, hijo);
            if (max < alt)
                max = alt;

            hijo = A.hermDrcho(hijo);
        }
        return max;
    }
}

template <typename T>
int desequilibrio(Agen<T> A)
{
    return altMax(A, A.raiz()) - altMin(A, A.raiz());
}

#endif