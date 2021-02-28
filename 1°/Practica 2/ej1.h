#ifndef EJ1_H_
#define EJ1_H_

#include "abin.h"

template<typename T>
bool similaresRec(const Abin<T> &A1,const Abin<T> &A2){
    return compSimilaresRec(A1,A2,A1.raiz(),A2.raiz());
}

template<typename T>
bool compSimilaresRec(const Abin<T> &A1,const Abin<T> &A2,typename Abin<T>::nodo n1,typename Abin<T>::nodo n2){
    if(n1 == Abin<T>::NODO_NULO && n2 == Abin<T>::NODO_NULO)
        return true;
    else if(n1 != Abin<T>::NODO_NULO && n2 != Abin<T>::NODO_NULO){
        return compSimilaresRec(A1,A2,A1.hijoDrcho(n1),A2.hijoDrcho(n2)) * 
               compSimilaresRec(A1,A2,A1.hijoIzqdo(n1),A2.hijoIzqdo(n2));
    }
    else
        return false;
}

#endif