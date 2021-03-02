#ifndef EJ2_H_
#define EJ2_H_
#include "abin.h"
#include "abin_E-S.h"

template<typename T>
int calcAlturaRec(Abin<T> &A, typename Abin<T>::nodo n) {
    if(n == Abin<T>::NODO_NULO)
        return -1;
    else
        return 1 + std::max(calcAlturaRec(A, A.hijoIzqdo(n)), calcAlturaRec(A, A.hijoDrcho(n)));
}

template<typename T>
int calcAltura(Abin<T> &A) {
    return calcAlturaRec(A, A.raiz());
}

int mayor(int a, int b) {
    return a > b;
}

#endif