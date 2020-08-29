#ifndef EJ3_H_
#define EJ3_H_

#include "agen.h"

template<typename T>
int desequilibrioAgen(const Agen<T> &A){
    return desequilibrioAgenRec(A,A.raiz());
}

template<typename T>
int desequilibrioAgenRec(const Agen<T> &A,typename Agen<T>::nodo n){
    
}

template<typename T>
int alturaNodo(const Agen<T> &A, typename Agen<T>::nodo n){
    typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
    int altura,alturamax;
    altura = alturamax = 0;
    if(hijo != Agen<T>::NODO_NULO){
        while(hijo != Agen<T>::NODO_NULO){
            altura = 1 + alturaNodo(A,hijo);
            if(alturamax < altura)
                alturamax = altura;
            hijo = A.hermDrcho(hijo);
        }
        return alturamax;
    }
    else 
        return 0;
}

#endif