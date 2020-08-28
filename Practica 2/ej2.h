#ifndef EJ2_H_
#define EJ2_H_

#include "abin.h"

template<typename T>
Abin<T> clonar(const Abin<T> &A1){
    Abin<T> A2;
    A2.insertarRaiz(A1.elemento(A1.raiz()));
    clonarRec(A1,A2,A1.raiz(),A2.raiz());
    return A2;
}

template<typename T>
void clonarRec(const Abin<T> &A1,Abin<T> &A2,typename Abin<T>::nodo n1,typename Abin<T>::nodo n2){
    if(A1.hijoIzqdo(n1) != Abin<T>::NODO_NULO){
        A2.insertarHijoIzqdo(n2,A1.elemento(A1.hijoIzqdo(n1)));
        clonarRec(A1,A2,A1.hijoIzqdo(n1),A2.hijoIzqdo(n2));
    }
    if(A1.hijoDrcho(n1) != Abin<T>::NODO_NULO){
        A2.insertarHijoDrcho(n2,A1.elemento(A1.hijoDrcho(n1)));
        clonarRec(A1,A2,A1.hijoDrcho(n1),A2.hijoDrcho(n2));
    }
}

#endif