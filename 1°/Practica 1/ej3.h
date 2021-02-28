#ifndef EJ3_H_
#define EJ3_H_

#include "abin.h"

template<typename T>
int profNodoRecv1(const Abin<T> &A, typename Abin<T>::nodo d){
    return contarProfNodoRecv1(A,d,A.raiz());
}

template<typename T>
int contarProfNodoRecv1(const Abin<T> &A, typename Abin<T>::nodo d, typename Abin<T>::nodo n){
    if(d == n)
        return 0;
    else if(n != Abin<T>::NODO_NULO){
        return 1 + std::max(contarProfNodoRecv1(A,d,A.hijoDrcho(n)),
                            contarProfNodoRecv1(A,d,A.hijoIzqdo(n)));
    }
    else
        return -100;
}

template<typename T>
int profNodoRecv2(const Abin<T> &A, typename Abin<T>::nodo d){
    if(A.padre(d) != Abin<T>::NODO_NULO)
        return 1 + profNodoRecv2(A,A.padre(d));
    else
        return 0;
}

#endif