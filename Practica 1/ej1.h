#ifndef EJ1_H_
#define EJ1_H_
#include "abin.h"
#include "colaenla.h"

template<typename T>
int numNodosRec(const Abin<T> &A){
    return contarNumNodosRec(A,A.raiz());
}

template<typename T>
int contarNumNodosRec(const Abin<T> &A,typename Abin<T>::nodo n){
    if(n != Abin<T>::NODO_NULO){
        return 1 + contarNumNodosRec(A,A.hijoDrcho(n)) + contarNumNodosRec(A,A.hijoIzqdo(n));
    }
    else
        return 0;
}

template<typename T>
int numNodos(const Abin<T> &A){
    int num = 0;
    if(A.raiz() != Abin<T>::NODO_NULO){
        typename Abin<T>::nodo n;
        Cola<typename Abin<T>::nodo> c;
        c.push(A.raiz());
        while(!c.vacia()){
            n = c.frente(); c.pop();
            if(n != Abin<T>::NODO_NULO){
                ++num;
                c.push(A.hijoDrcho(n));
                c.push(A.hijoIzqdo(n));
            }
        }
    }   
    return num;
}

#endif