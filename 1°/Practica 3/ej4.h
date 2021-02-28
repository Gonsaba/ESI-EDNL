#ifndef EJ4_H_
#define EJ4_H_

#include "agen.h"

template<typename T>
void podav1(Agen<T> &A,T x){
    typename Agen<T>::nodo n = buscarNodo(A,x,A.raiz());
    if(A.hijoIzqdo(n) != Agen<T>::NODO_NULO){
        borrarRec(A,n);
    }
}

template<typename T>
void podav2(Agen<T> &A,T x){
    typename Agen<T>::nodo n = buscarNodo(A,x,A.raiz());
    if(A.hijoIzqdo(n) != Agen<T>::NODO_NULO){
        borrarRec(A,n);
    }
    typename Agen<T>::nodo padre = A.padre(n);
    if(A.hijoIzqdo(padre) != n){
        typename Agen<T>::nodo hermano = A.hijoIzqdo(padre);
        while(A.hermDrcho(hermano) != n){
            hermano = A.hermDrcho(hermano);
        }
        A.eliminarHermDrcho(hermano);
    }
}

template<typename T>
void borrarRec(Agen<T> &A,typename Agen<T>::nodo n){
    typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
    while(hijo != Agen<T>::NODO_NULO){
        if(A.hijoIzqdo(hijo) != Agen<T>::NODO_NULO)
            borrarRec(A,hijo);
        A.eliminarHijoIzqdo(n);
        hijo = A.hijoIzqdo(n);
    }
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