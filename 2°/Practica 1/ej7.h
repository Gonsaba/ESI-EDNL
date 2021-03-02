#ifndef EJ7_H_
#define EJ7_H_
#include "abin.h"
#include "abin_E-S.h"

template<typename T>
bool pseudocompletoRec(Abin<T> &A, typename Abin<T>::nodo n) {
    if(n == Abin<T>::NODO_NULO) 
        return true;
    else if(A.altura(n) == 1) {
        if(A.hijoDrcho(n) != Abin<T>::NODO_NULO && A.hijoIzqdo(n) != Abin<T>::NODO_NULO)
            return true;
        else
        return false;
    }
    else 
        return pseudocompletoRec(A, A.hijoDrcho(n)) && pseudocompletoRec(A, A.hijoIzqdo(n));
}

template<typename T>
bool pseudocompleto(Abin<T> &A) {
    return pseudocompletoRec(A, A.raiz());
}

#endif