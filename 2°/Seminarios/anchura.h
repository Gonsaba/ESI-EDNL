#ifndef ANCHURA_H_
#define ANCHURA_H_
#include "abin.h"
#include "colaenla.h"
#include "iostream"

template <typename T>
void anchura(Abin<T> A) {
    Cola<typename Abin<T>::nodo> c;
    typename Abin<T>::nodo n;
    c.push(A.raiz());
    while(!c.vacia()) {
        n = c.frente();
        c.pop();
        if(n != Abin<T>::NODO_NULO) {
            if (n != Abin<T>::NODO_NULO)
                std::cout << A.elemento(n) << std::endl;
            c.push(A.hijoIzqdo(n));
            c.push(A.hijoDrcho(n));
        }
    }
}

#endif