#ifndef EJ3_H_
#define EJ3_H_
#include "abin.h"
#include "abin_E-S.h"

template<typename T>
int calcProfRec(Abin<T> &A, typename Abin<T>::nodo n) {
    if(n == Abin<T>::NODO_NULO)
        return -1;
    else
        return 1 + calcProfRec(A, A.padre(n));
}

#endif