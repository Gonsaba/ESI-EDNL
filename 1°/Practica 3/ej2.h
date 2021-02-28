#ifndef EJ2_H_
#define EJ2_H_

#include "agen.h"

template<typename T>
int profundidadv1(const Agen<T> &A,typename Agen<T>::nodo n){
    if(A.padre(n) != Agen<T>::NODO_NULO)
        return 1 + profundidadv1(A,A.padre(n));
    else 
        return 0;
}

template<typename T>
int profundidadv2(const Agen<T> &A,typename Agen<T>::nodo d){
    return profundidadv2Rec(A,A.raiz(),d);
}

template<typename T>
int profundidadv2Rec(const Agen<T> &A,typename Agen<T>::nodo n,typename Agen<T>::nodo d){
    if(n == d)
        return 0;
    else if(n != Agen<T>::NODO_NULO){
        return std::max(profundidadv2Rec(A,A.hermDrcho(n),d),
                        profundidadv2Rec(A,A.hijoIzqdo(n),d) + 1);
    }
    else
        return -1000000000;
}

#endif