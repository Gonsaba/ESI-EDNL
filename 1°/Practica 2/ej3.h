#ifndef EJ3_H_
#define EJ3_H_

#include <stdlib.h>
#include "abin.h"

template<typename T>
int calcularArbol(const Abin<T> &A){
    return calcularArbolRec(A,A.raiz());
}

template<typename T>
int calcularArbolRec(const Abin<T> &A,typename Abin<T>::nodo n){
    int a;
    switch (A.elemento(n))
    {
    case '+':
        return calcularArbolRec(A,A.hijoIzqdo(n)) + calcularArbolRec(A,A.hijoDrcho(n));
        break;
    case '-':
        return calcularArbolRec(A,A.hijoIzqdo(n)) - calcularArbolRec(A,A.hijoDrcho(n));
        break;
    case '*':
        return calcularArbolRec(A,A.hijoIzqdo(n)) * calcularArbolRec(A,A.hijoDrcho(n));
        break;
    case '/':
        return calcularArbolRec(A,A.hijoIzqdo(n)) / calcularArbolRec(A,A.hijoDrcho(n));
        break;
    default:
        return (int)A.elemento(n) - 48;
        break;
    }
}

#endif