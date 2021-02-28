#ifndef EJ1_H_
#define EJ1_H_
#include "abin.h"
#include "abin_E-S.h"

template<typename T>
int contarNodosRec(Abin<T> &A, typename Abin<T>::nodo n)
{
    if (n == Abin<T>::NODO_NULO)
        return 0;
    else
        return 1 + contarNodosRec(A, A.hijoIzqdo(n)) + contarNodosRec(A, A.hijoDrcho(n));
}

template <typename T>
int contarNodos(Abin<T> A)
{
    return contarNodosRec(A, A.raiz());
}

#endif