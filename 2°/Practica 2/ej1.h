#ifndef EJ1_H_
#define EJ1_H_
#include "abin.h"

template<typename T>
bool abinIgual(Abin<T> &A, Abin<T> &B) {
    if (A.raiz() == Abin<T>::NODO_NULO && B.raiz() == Abin<T>::NODO_NULO)
        return true;
    else if (A.raiz() == Abin<T>::NODO_NULO || B.raiz() == Abin<T>::NODO_NULO)
        return false;
    else
        return abinIgualRec(A, A.hijoIzqdo(A.raiz()), B, B.hijoIzqdo(B.raiz())) 
            && abinIgualRec(A, A.hijoDrcho(A.raiz()), B, B.hijoDrcho(B.raiz()));
}

template <typename T>
bool abinIgualRec(Abin<T> &A, typename Abin<T>::nodo na,
 Abin<T> &B, typename Abin<T>::nodo nb) {
    if (na == Abin<T>::NODO_NULO && nb == Abin<T>::NODO_NULO)
        return true;
    else if (na == Abin<T>::NODO_NULO || nb == Abin<T>::NODO_NULO)
        return false;
    else
        return abinIgualRec(A, A.hijoIzqdo(na), B, B.hijoIzqdo(nb)) 
            && abinIgualRec(A, A.hijoDrcho(na), B, B.hijoDrcho(nb));
}

#endif