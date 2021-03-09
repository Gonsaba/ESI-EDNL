#ifndef EJ7_H_
#define EJ7_H_
#include "abin.h"
#include "abin_E-S.h"

template<typename T>
bool pseudocompletoRec(Abin<T> &A, typename Abin<T>::nodo n) {
    if(n == Abin<T>::NODO_NULO) return true;
    else if(A.altura(n) == 0) return true;
    else if(A.altura(n) == 1) {
        if(A.hijoDrcho(n) != Abin<T>::NODO_NULO && A.hijoIzqdo(n) != Abin<T>::NODO_NULO)
            return true;
        else
            return false;
    }
    else {
        if(A.altura(A.hijoDrcho(n)) > A.altura(A.hijoIzqdo(n)))
            return pseudocompletoRec(A.hijoDrcho(n));
        else if(A.altura(A.hijoDrcho(n)) < A.altura(A.hijoIzqdo(n)))
            return pseudocompletoRec(A.hijoIzqdo(n));
        else
            return pseudocompletoRec(A, A.hijoDrcho(n))
                && pseudocompletoRec(A, A.hijoIzqdo(n));
    }
}

template<typename T>
bool pseudocompleto(Abin<T> &A) {
    return pseudocompletoRec(A, A.raiz());
}

#endif