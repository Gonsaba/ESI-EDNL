#ifndef PREORDITER_H_
#define PREORDITER_H_
#include "abin.h"
#include "pilaenla.h"
#include "iostream"

template <typename T>
void procesar(Abin<T> A, typename Abin<T>::nodo n) {
    if(n != Abin<T>::NODO_NULO)
        std::cout << A.elemento(n) << std::endl;
}

template <typename T>
void preordIter(Abin<T> &A) {
    Pila<typename Abin<T>::nodo> p;
    typename Abin<T>::nodo n = A.raiz();
    do{
        if(n != Abin<T>::NODO_NULO) {
            if (n != Abin<T>::NODO_NULO)
                std::cout << A.elemento(n) << std::endl;
            if(A.hijoDrcho(n) != Abin<T>::NODO_NULO)
                p.push(A.hijoDrcho(n));
            n = A.hijoIzqdo(n);
        }
        else {
            n = p.tope();
            p.pop();
        }
    }while(!(n == Abin<T>::NODO_NULO && p.vacia()));
}

#endif