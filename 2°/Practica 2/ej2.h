#ifndef EJ2_H_
#define EJ2_H_
#include "abin.h"

template <typename T>
Abin<T> abinRef(Abin<T> &A) {
    Abin<T> B;
    if(A.raiz() != Abin<T>::NODO_NULO) 
    {
        B.insertarRaiz(A.elemento(A.raiz()));
        abinRefRec(A, A.raiz(), B, B.raiz());
    }
    return B;
}

template <typename T>
void abinRefRec(Abin<T> &A, typename Abin<T>::nodo na, 
    Abin<T> &B, typename Abin<T>::nodo nb) {
    if (A.hijoIzqdo(na) != Abin<T>::NODO_NULO)
    {
        B.insertarHijoDrcho(nb, A.elemento(A.hijoIzqdo(na)));
        abinRefRec(A, A.hijoIzqdo(na), B, B.hijoDrcho(nb));
    }
    if (A.hijoDrcho(na) != Abin<T>::NODO_NULO)
    {
        B.insertarHijoIzqdo(nb, A.elemento(A.hijoDrcho(na)));
        abinRefRec(A, A.hijoDrcho(na), B, B.hijoIzqdo(nb));
    }
}

#endif