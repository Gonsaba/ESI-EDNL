#ifndef EJ4_H_
#define EJ4_H_

#include "agen.h"

template<typename T>
void poda(Agen<T> &A,T x){
    typename Agen<T>::nodo n = buscarNodo(A,x,A.raiz());
    if(A.hijoIzqdo(n) != Agen<T>::NODO_NULO){

    }
}

template<typename T>
void borrarRec(Agen<T> &A,typename Agen<T>::nodo n){
    
}

template<typename T>
typename Agen<T>::nodo buscarNodo(const Agen<T> &A,T x,typename Agen<T>::nodo n){
    if(n != Agen<T>::NODO_NULO){
        if(A.elemento(n) == x){
            return n;
        }
        else{
            typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
            typename Agen<T>::nodo nodo;
            while(hijo != Agen<T>::NODO_NULO){
                nodo = buscarNodo(A,x,hijo);
                if(nodo != Agen<T>::NODO_NULO)
                    return nodo;
                hijo = A.hermDrcho(hijo);
            }
        }
    }
    else
        return n;
}

#endif