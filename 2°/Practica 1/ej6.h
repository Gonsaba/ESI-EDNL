#ifndef EJ6_H_
#define EJ6_H_
#include "abin.h"
#include "abin_E-S.h"

template<typename T>
int desequilibrioRec(Abin<T> &A, typename Abin<T>::nodo n) {
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        return std::max(std::abs(A.altura(A.hijoIzqdo(n)) 
            - A.altura(A.hijoDrcho(n))),
             std::max(desequilibrioRec(A, A.hijoIzqdo(n)),
              desequilibrioRec(A, A.hijoDrcho(n))));
}

template<typename T>
int desequilibrio(Abin<T> &A) {
    return desequilibrioRec(A, A.raiz());
}

#endif