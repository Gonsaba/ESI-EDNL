#include "abin.h"

template <typename T>
void eliminar(Abin<T> &A, typename Abin<T>::nodo n)
{
    typename Abin<T>::nodo nRes;
    nRes = hundir(A, n);

    if(n == A.raiz())
        A.eliminarRaiz();
    else if(n == A.hijoIzqdo(A.padre(n)))
        A.eliminarHijoIzqdo(A.padre(n));
    else
        A.eliminarHijoDrcho(A.padre(n));
}

template <typename T>
typename Abin<T>::nodo hundir(Abin<T> &A, typename Abin<T>::nodo n)
{
    if(A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO)
        return n;
    else if (A.hijoDrcho(n) == Abin<T>::NODO_NULO)
    {
        A.elemento(n) = A.elemento(A.hijoIzqdo(n));
        hundir(A, A.hijoIzqdo(n));
    }
    else if (A.hijoIzqdo(n) == Abin<T>::NODO_NULO)
    {
        A.elemento(n) = A.elemento(A.hijoDrcho(n));
        hundir(A, A.hijoDrcho(n));
    }
    else
    {
        A.elemento(n) = std::min(A.elemento(A.hijoIzqdo(n)), A.elemento(A.hijoDrcho(n)));
        if (A.elemento(A.hijoIzqdo(n)) < A.elemento(A.hijoDrcho(n)))
            hundir(A, A.hijoIzqdo(n));
        else
            hundir(A, A.hijoDrcho(n));
    }
}

template <typename T>
void busquedaRec(Abin<T> &A, typename Abin<T>::nodo n, T e)
{
    if(n != Abin<T>::NODO_NULO)
    {
        if(e == A.elemento(n))
            hundir(A, n);
        else if (e > A.elemento(n))
        {
            busquedaRec(A, A.hijoIzqdo(n), e);
            busquedaRec(A, A.hijoDrcho(n), e);
        }
    }
}

template <typename T>
void eliminar(Abin<T> &A, T e) { busquedaRec(A, A.raiz(), e); }