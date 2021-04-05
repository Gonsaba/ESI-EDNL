#ifndef EJ4_H_
#define EJ4_H_
#include "agen.h"

template <typename T>
void podaRec(Agen<T> &A, typename Agen<T>::nodo n)
{
    while(A.hijoIzqdo(n) != Agen<T>::NODO_NULO)
    {
        podaRec(A, A.hijoIzqdo(n));
        A.eliminarHijoIzqdo(n);
    }
}

template <typename T>
void podaNodo(Agen<T> &A, typename Agen<T>::nodo n, T e)
{
    bool eliminado = false;
    typename Agen<T>::nodo hijo;
    if(A.elemento(A.hijoIzqdo(n)) == e)
        A.eliminarHijoIzqdo(n);
    else
    {
        hijo = A.hijoIzqdo(n);
        while(!eliminado || hijo == Agen<T>::NODO_NULO)
        {
            if (A.elemento(A.hermDrcho(hijo)) == e)
            {
                A.eliminarHermDrcho(hijo);
                eliminado = true;
            }
            else
                hijo = A.hermDrcho(hijo);
        }
    }
}

template <typename T>
void podaBusquedaRec(Agen<T> &A, typename Agen<T>::nodo n, T e)
{
    typename Agen<T>::nodo hijo;
    if(n != Agen<T>::NODO_NULO)
    {
        // std::cout << e << " =? " << A.elemento(n) << std::endl;
        if(A.elemento(n) == e)
        {
            podaRec(A, n);
            podaNodo(A, A.padre(n), e);
        }
        else
        {
            hijo = A.hijoIzqdo(n);
            while(hijo != Agen<T>::NODO_NULO)
            {
                podaBusquedaRec(A, hijo, e);
                hijo = A.hermDrcho(hijo);
            }
        }  
    }
}

template <typename T>
void poda(Agen<T> &A, T e)
{
    if (!A.arbolVacio())
        podaBusquedaRec(A, A.raiz(), e);
}

#endif