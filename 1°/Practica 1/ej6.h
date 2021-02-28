#ifndef EJ6_H_
#define EJ6_H_

#include "abin.h" 

template<typename T>
int desequilibrioRec(Abin<T> A){
    return calcDesequilibrioRec(A,A.raiz());
}

template<typename T>
int calcDesequilibrioRec(Abin<T> A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else{
        return std::max(abs(A.altura(A.hijoDrcho(n)) - A.altura(A.hijoIzqdo(n))),std::max(calcDesequilibrioRec(A,A.hijoDrcho(n)),calcDesequilibrioRec(A,A.hijoIzqdo(n))));
    }
}

#endif